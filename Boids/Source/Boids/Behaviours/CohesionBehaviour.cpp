// Fill out your copyright notice in the Description page of Project Settings.

#include "CohesionBehaviour.h"

CohesionBehaviour::CohesionBehaviour() : Behaviour()
{
}

CohesionBehaviour::CohesionBehaviour(float weight) : Behaviour(weight)
{
}

CohesionBehaviour::~CohesionBehaviour()
{
}

FVector CohesionBehaviour::operator()(const ABoidAgent& currentBoid, const std::vector<ABoidAgent*>& boidsInView) const
{
	FVector cohesionMove(0, 0, 0);

	if (boidsInView.size() <= 0) {
		return cohesionMove;
	}

	//add all points together and average
	for (auto& pos : boidsInView) {
		cohesionMove += pos->GetActorTransform().GetLocation();
	}
	cohesionMove *= 1.0f / boidsInView.size();

	//create offset from agent position
	cohesionMove -= currentBoid.GetActorTransform().GetLocation();

	return cohesionMove * weight;
}