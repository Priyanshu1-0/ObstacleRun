// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform2.generated.h"

UCLASS()
class OBSTACLEASSAULT_API AMovingPlatform2 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform2();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void MovePlatform(float DeltaTime);
	void RotatePlatform(float DeltaTime);

	float GetDistanceMoved();
	
	UPROPERTY(EditAnywhere)
	FVector PlatformVelocity = FVector(100.0f, 0.0f, 0.0f);

	UPROPERTY(EditAnywhere) 
	float MoveDistance = 100.0f;
	

	UPROPERTY(EditAnywhere) 
	float DistanceMoved = 0.0f;


	UPROPERTY(EditAnywhere)
	FRotator RotationVelocity;

	FVector StartLocation;

};
