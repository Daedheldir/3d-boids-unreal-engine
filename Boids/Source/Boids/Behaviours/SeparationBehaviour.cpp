// Fill out your copyright notice in the Description page of Project Settings.

#include "SeparationBehaviour.h"

SeparationBehaviour::SeparationBehaviour() : Behaviour()
{
}

SeparationBehaviour::SeparationBehaviour(float weight) : Behaviour(weight)
{
}

SeparationBehaviour::~SeparationBehaviour()
{
}

FVector SeparationBehaviour::operator()(const ABoidAgent& currentBoid, const std::vector<ABoidAgent*>& boidsInView) const
{
	FVector avoidanceMove(0, 0, 0);

	if (boidsInView.size() <= 0) {
		return avoidanceMove;
	}
	//add all points together and average
	int nAvoid = 0;

	FVector closestAgentPos = boidsInView[0]->GetActorTransform().GetLocation();

	for (auto& neighbourPos : boidsInView)
	{
		FVector relativeVec = currentBoid.GetActorTransform().GetLocation() - neighbourPos->GetActorTransform().GetLocation();

		if (relativeVec.SizeSquared() < 2000.0f)
		{
			nAvoid++;
			avoidanceMove += relativeVec;
		}
	}

	if (nAvoid > 0)
	{
		avoidanceMove *= 1.0f / (float)nAvoid;
	}

	return avoidanceMove * weight;
}