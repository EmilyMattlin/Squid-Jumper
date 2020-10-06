// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "CoreMinimal.h"
#include "SquidCharacter.generated.h"

UCLASS()
class SQUIDV2_API ASquidCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASquidCharacter();
	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* VisualMesh;
	UPROPERTY(VisibleAnywhere)
		bool rightDir;
	UPROPERTY(VisibleAnywhere)
		float DistBtwnBuildings;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// Handles input for moving forward and backward.
	
	// Handles input for moving right and left.
	UFUNCTION() //Engine is aware of of function
		void MoveRight(float Value);

	// FPS camera.
	UPROPERTY(VisibleAnywhere)
		class UCameraComponent* ThirdPCameraComponent;

	// Sets jump flag when key is pressed.
	UFUNCTION()
		void StartJumpRight();
	
	// Sets jump flag when key is pressed.
	UFUNCTION()
		void StartJumpLeft();

	// Clears jump flag when key is released.
	UFUNCTION()
		void StopJump();
	
	enum side { left, right };
};
