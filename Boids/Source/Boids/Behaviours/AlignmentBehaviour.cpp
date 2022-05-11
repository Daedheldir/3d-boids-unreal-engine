// Fill out your copyright notice in the Description page of Project Settings.

#include "AlignmentBehaviour.h"

AlignmentBehaviour::AlignmentBehaviour() : Behaviour()
{
}

AlignmentBehaviour::AlignmentBehaviour(float weight) : Behaviour{ weight } {}

AlignmentBehaviour::~AlignmentBehaviour()
{
}

FVector AlignmentBehaviour::operator()(const ABoidAgent& currentBoid, const std::vector<ABoidAgent*>& boidsInView) const
{
	FVector alignmentMove(0, 0, 0);

	if (boidsInView.size() <= 0) {
		alignmentMove = currentBoid.getAcceleration();
		return alignmentMove;
	}

	for (auto& heading : boidsInView) {
		alignmentMove += heading->getAcceleration();
	}

	alignmentMove *= 1.0f / boidsInView.size();

	return alignmentMove * weight;
}