// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "BoidAgent.generated.h"

UCLASS()
class BOIDS_API ABoidAgent : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABoidAgent();
	void Move(float DeltaTime);

	FVector getVelocity() const;
	FVector getAcceleration() const;
	void setAcceleration(const FVector acceleration);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	FVector boidVelocity;
	FVector boidAcceleration;
};
