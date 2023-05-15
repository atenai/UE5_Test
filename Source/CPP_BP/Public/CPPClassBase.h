#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPPClassBase.generated.h"

UCLASS()
class CPP_BP_API ACPPClassBase : public AActor
{
	GENERATED_BODY()
	
public:	
	ACPPClassBase();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	// Scene Component
	UPROPERTY(EditAnywhere)
	TObjectPtr<USceneComponent> DefaultSceneRoot;

	// StaticMesh Component
	UPROPERTY(EditAnywhere)
	TObjectPtr<UStaticMeshComponent> StaticMesh;

	// �e�N���X�̃����o�֐�
	//�u���[�v�����g�Ńm�[�h�Ƃ��Ĉ�����悤�ɂȂ�
	UFUNCTION(BlueprintCallable, Category=CPP_And_Blueprint)
	void CallParentFunc();

	// �e�N���X�̃f�[�^�����o
	//���N���X�̃f�[�^�����o[VarParentNum]��Default�l��ύX������ASet�֐����Ăяo����悤�ɂȂ�܂��B
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Default)
	int VarParentNum = 10;
};
