// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform2.h"

// Sets default values
AMovingPlatform2::AMovingPlatform2()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void TestFunction() {

	UE_LOG(LogTemp, Display, TEXT("TestFunction called"));
}

// Called when the game starts or when spawned
void AMovingPlatform2::BeginPlay()
{
	Super::BeginPlay();
	TestFunction();
	StartLocation = GetActorLocation();

}



// Called every frame
void AMovingPlatform2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);

}

void AMovingPlatform2::MovePlatform(float DeltaTime) {



	DistanceMoved = GetDistanceMoved();

	if(DistanceMoved >= MoveDistance) {

		float overshoot = DistanceMoved - MoveDistance;
		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		FVector newStartLocation = StartLocation + (MoveDirection * MoveDistance);
		SetActorLocation(newStartLocation);
		StartLocation = newStartLocation;
		PlatformVelocity = -PlatformVelocity;
	} 
	else {
		FVector CurrentLocation = GetActorLocation();

		CurrentLocation = CurrentLocation + (PlatformVelocity * DeltaTime);


		SetActorLocation(CurrentLocation);
	}

}

void AMovingPlatform2::RotatePlatform(float DeltaTime) {
	AddActorLocalRotation(RotationVelocity * DeltaTime);
}

float AMovingPlatform2::GetDistanceMoved()
{
	return FVector::Dist(StartLocation, GetActorLocation());
}

