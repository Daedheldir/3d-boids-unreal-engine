// Fill out your copyright notice in the Description page of Project Settings.

#include "Flock.h"

// Sets default values
AFlock::AFlock() :alignBehav{ 1.0f }, sepBehav{ 1.0f }, cohBehav{ 1.0f }
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	mesh->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));

	if (CubeVisualAsset.Succeeded())
	{
		mesh->SetStaticMesh(CubeVisualAsset.Object);
		mesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	}
}

// Called when the game starts or when spawned
void AFlock::BeginPlay()
{
	Super::BeginPlay();

	squareMaxSpeed = maxSpeed * maxSpeed;
	squareNeighbourRadius = neighbourRadius * neighbourRadius;
	squareNeighbourAvoidanceRadius = neighbourAvoidanceRadius * neighbourAvoidanceRadius;
	squareObstacleAvoidanceRadius = obstacleAvoidanceRadius * obstacleAvoidanceRadius;

	//spawn actors
	if (UsefulActorBP)
	{
		for (int i = 0; i < this->startingCount; ++i) {
			FVector agentPosition = GetTransform().GetLocation() + FMath::VRand() * startingCount * agentDensity;
			FRotator agentRotation = FVector(FMath::RandPointInCircle(0.5), 0).ToOrientationRotator();

			FActorSpawnParameters params;
			params.Owner = this;

			ABoidAgent* actor = GetWorld()->SpawnActor<ABoidAgent>(UsefulActorBP, agentPosition, agentRotation, params);

			FAttachmentTransformRules attRules(EAttachmentRule(), false);
			actor->AttachToActor(this, attRules);
			agents.Add(actor);
		}
	}
}

// Called every frame
void AFlock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	for (auto boid : agents) {
		std::vector<ABoidAgent*> boidsInView;
		GetBoidsInView(*boid, boidsInView);

		FVector accelerationVec{ 0,0,0 };

		accelerationVec += alignBehav(*boid, boidsInView);
		accelerationVec += sepBehav(*boid, boidsInView);
		accelerationVec += cohBehav(*boid, boidsInView);

		boid->setAcceleration(FMath::Lerp(boid->getAcceleration(), accelerationVec, 1.0f));
		boid->Move(DeltaTime);
	}
}