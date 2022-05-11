// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Behaviour.h"

/**
 *
 */
class BOIDS_API CohesionBehaviour : public Behaviour
{
public:
	CohesionBehaviour();
	CohesionBehaviour(float weight);
	~CohesionBehaviour();

	FVector operator() (const ABoidAgent& currentBoid, const std::vector<ABoidAgent*>& boidsInView) const;
};
