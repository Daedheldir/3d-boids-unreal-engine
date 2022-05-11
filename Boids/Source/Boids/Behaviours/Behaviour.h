// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../BoidAgents/BoidAgent.h"
#include <vector>

/**
 *
 */
class BOIDS_API Behaviour
{
public:
	Behaviour();
	Behaviour(float weight);
	virtual ~Behaviour();

	virtual FVector operator () (const ABoidAgent& currentBoid, const std::vector<ABoidAgent*>& boidsInView) const = 0;

public:
	const float weight;
};
