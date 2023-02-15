#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnemyCharacter.generated.h"

UCLASS()
class BEHAVIORTREE_API AEnemyCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    AEnemyCharacter();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

public:
    UPROPERTY(VisibleAnywhere, Category = "AI")
        class UPawnSensingComponent* PawnSensingComp;

    UFUNCTION()
        void OnSeePlayer(APawn* Pawn);

};
