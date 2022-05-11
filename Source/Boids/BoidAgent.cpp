// Fill out your copyright notice in the Description page of Project Settings.

#include "BoidAgent.h"

// Sets default values
ABoidAgent::ABoidAgent()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
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


void ABoidAgent::Move(FVector newVelocity, float DeltaTime)
{
	this->velocity = FMath::Lerp(this->velocity, newVelocity, DeltaTime);

	FVector NewLocation = GetActorLocation();
	FRotator NewRotation = GetActorRotation();

	NewRotation = this->velocity.Rotation();
	NewLocation += DeltaTime * this->velocity;
	
	SetActorLocationAndRotation(NewLocation, NewRotation);
}