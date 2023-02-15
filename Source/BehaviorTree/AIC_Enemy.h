#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTreeCharacter.h"
#include "AIC_Enemy.generated.h"

UCLASS()
class BEHAVIORTREE_API AAIC_Enemy : public AAIController
{
    GENERATED_BODY()
    
public:
    AAIC_Enemy(const class FObjectInitializer& ObjectInitializer);

public:
    void SetPlayerKey(APawn* player);

    UFUNCTION()
        ABehaviorTreeCharacter* GetPlayerKey();

    UPROPERTY()
        UBehaviorTreeComponent* BehaviorComp;

    UPROPERTY()
        UBlackboardComponent* BlackboardComp;

    UPROPERTY(EditDefaultsOnly, Category = AI)
        FName PlayerKeyName;

protected:
    // AIControllerのPawn所持
    virtual void OnPossess(class APawn* InPawn) override;
    
    // AIControllerのPawn所持解除
    virtual void OnUnPossess() override;

    virtual void BeginPlay() override;

    UPROPERTY(EditDefaultsOnly, Category = AI)
        class UBehaviorTree* BehaviorTree;

    FORCEINLINE UBehaviorTreeComponent* GetBehaviorComp() const { return BehaviorComp; }
    FORCEINLINE UBlackboardComponent* GetBlackboardComp() const { return BlackboardComp; }
};
    

