// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BoidAgent.h"

#include "Flock.generated.h"

UCLASS()
class BOIDS_API AFlock : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AFlock();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:

	UPROPERTY(EditAnywhere, Category = "ActorSpawning")
		TSubclassOf<ABoidAgent> UsefulActorBP;

	UPROPERTY(EditAnywhere, meta = (ClampMin = "10.0", ClampMax = "255.0", UIMin = "10.0", UIMax = "255.0"))
		uint8 startingCount = 100;

	UPROPERTY(EditAnywhere, meta = (ClampMin = "1.0", ClampMax = "100.0", UIMin = "1.0", UIMax = "100.0"))
		float driveFactor = 10.f;

	UPROPERTY(EditAnywhere, meta = (ClampMin = "1.0", ClampMax = "100.0", UIMin = "1.0", UIMax = "0.0"))
		float maxSpeed = 5.f;

	UPROPERTY(EditAnywhere, meta = (ClampMin = "1.0", ClampMax = "1000.0", UIMin = "1.0", UIMax = "1000.0"))
		float neighbourRadius = 1.5f;

	UPROPERTY(EditAnywhere, meta = (ClampMin = "0.0", ClampMax = "10.0", UIMin = "0.0", UIMax = "10.0"))
		float obstacleAvoidanceRadius = 3.f;

	UPROPERTY(EditAnywhere, meta = (ClampMin = "0.1", ClampMax = "1000.0", UIMin = "0.1", UIMax = "1000.0"))
		float neighbourAvoidanceRadius = 0.5f;

	UPROPERTY(EditAnywhere, meta = (ClampMin = "0.0", ClampMax = "360.0", UIMin = "0.0", UIMax = "360.0"))
		float agentFOV = 270.f;

private:
	UStaticMeshComponent* mesh;
	const float agentDensity = 10.f;

	TArray<ABoidAgent*> agents;

	float squareNeighbourAvoidanceRadius = 0;
	float squareObstacleAvoidanceRadius = 0;

	float squareMaxSpeed;
	float squareNeighbourRadius;
};
