// Fill out your copyright notice in the Description page of Project Settings.

#include "BoidAgent.h"

// Sets default values
ABoidAgent::ABoidAgent()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	boidAcceleration = FVector(
		FMath::RandRange(-10.0f, 10.0f),
		FMath::RandRange(-10.0f, 10.0f),
		FMath::RandRange(-10.0f, 10.0f)
	);
}

// Called when the game starts or when spawned
void ABoidAgent::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABoidAgent::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABoidAgent::Move(float DeltaTime)
{
	this->boidVelocity += boidAcceleration * DeltaTime;

	FVector NewLocation = GetActorLocation();
	FRotator NewRotation = GetActorRotation();

	NewRotation = this->boidVelocity.Rotation();
	NewLocation += DeltaTime * this->boidVelocity;

	SetActorLocationAndRotation(NewLocation, NewRotation);
}

FVector ABoidAgent::getVelocity() const
{
	return this->boidVelocity;
}

FVector ABoidAgent::getAcceleration() const
{
	return this->boidAcceleration;
}

void ABoidAgent::setAcceleration(const FVector acceleration)
{
	this->boidAcceleration = acceleration;
}