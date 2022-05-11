// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Behaviour.h"

/**
 *
 */
class BOIDS_API SeparationBehaviour : public Behaviour
{
public:
	SeparationBehaviour();
	SeparationBehaviour(float weight);
	~SeparationBehaviour();

	FVector operator() (const ABoidAgent& currentBoid, const std::vector<ABoidAgent*>& boidsInView) const;
};
