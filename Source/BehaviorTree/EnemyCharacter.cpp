#include "EnemyCharacter.h"
#include "Perception/PawnSensingComponent.h"
#include "Kismet/KismetSystemLibrary.h"

#include "BehaviorTreeCharacter.h"
#include "AIC_Enemy.h"

AEnemyCharacter::AEnemyCharacter()
{
    PrimaryActorTick.bCanEverTick = true;

    PawnSensingComp = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("PawnSensingComp"));

    // 視野
    PawnSensingComp->SetPeripheralVisionAngle(60.f);
    // 見える範囲
    PawnSensingComp->SightRadius = 2000;
    PawnSensingComp->OnSeePawn.AddDynamic(this, &AEnemyCharacter::OnSeePlayer);
}

void AEnemyCharacter::BeginPlay()
{
    Super::BeginPlay();

}

void AEnemyCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}

void AEnemyCharacter::OnSeePlayer(APawn* Pawn)
{
    AAIC_Enemy* AIController = Cast<AAIC_Enemy>(GetController());
    // プレイヤー
    ABehaviorTreeCharacter* player = Cast<ABehaviorTreeCharacter>(Pawn);

    if (AIController && player)
    {
        // AIControllerにプレイヤー情報を設定
        AIController->SetPlayerKey(player);
    }

    // 視野に入ったら画面に"See"と表示
    UKismetSystemLibrary::PrintString(this, "See", true, true, FColor::Blue, 2.f);
}
