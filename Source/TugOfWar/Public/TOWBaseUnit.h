// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//My header files include here
#include "TOWGameMode.h"

//UE's header files include here
#include "Engine/DataTable.h"

//Auto generated
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TOWBaseUnit.generated.h"

const UINT8 MAX_DEFENSE = 100;

UENUM(BlueprintType)
enum class ETOWCamp : uint8
{
	ENeutral UMETA(DisplayName = "Neutral"),
	ERed UMETA(DisplayName = "RedCamp"),
	EBlue UMETA(DisplayName = "BlueCamp"),
};

UENUM(BlueprintType)
enum class ETOWDamageType : uint8
{
	EPhysicalDamage UMETA(DisplayName = "PhysicalDamage"),
	EMagicDamage UMETA(DisplayName = "MagicDamage"),
	ETrueDamage UMETA(DisplayName = "TrueDamage"),
};

USTRUCT()
struct FUnitBaseAttribute : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

		//Unit's camp info.
	UPROPERTY(EditAnywhere)
		ETOWCamp unitCamp = ETOWCamp::ENeutral;

	UPROPERTY(EditAnywhere)
		UINT16 maxLifeValue = 0;
	UPROPERTY(EditAnywhere)
		UINT16 currentLifeValue = 0;

	UPROPERTY(EditAnywhere)
		UINT8 physicalDefense = 0;
	UPROPERTY(EditAnywhere)
		UINT8 magicDefense = 0;

	UPROPERTY(EditAnywhere)
		UINT8 physicalPenetration = 0;
	UPROPERTY(EditAnywhere)
		UINT8 magicPenetration = 0;

	UPROPERTY(EditAnywhere)
		UINT16 physicalDamage = 0;
	UPROPERTY(EditAnywhere)
		UINT16 magicDamage = 0;
};

UCLASS()
class TUGOFWAR_API ATOWBaseUnit : public ACharacter
{
	GENERATED_BODY()

//Public function write here.
public:
	// Sets default values for this character's properties
	ATOWBaseUnit();

	/*
	 * Add damage to this unit.
	 * @param damageCauser. the damage's causer.
	 * @param damageValue. the damage's base value.
	 * @param damagePenetration. the damage's penetration.
	 * @param damageType. the damage's type.
	 **/
	virtual UINT16 ApplyDamage(ATOWBaseUnit* damageCauser, UINT16 damageValue, UINT16 damagePenetration, ETOWDamageType damageType);
	virtual void Death(ATOWBaseUnit* deathCauser);

	void RunBuff();
	void AddBuff(class UTOWBuff* buff);

//Public value write here.
public:
	//Unit base attribute
	UPROPERTY(EditAnywhere, Category = "BaseAttributes")
		FUnitBaseAttribute baseAttribute;

//Private value write here.
private:
	UPROPERTY()
		TArray<class UTOWBuff*> buffList;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	
};
