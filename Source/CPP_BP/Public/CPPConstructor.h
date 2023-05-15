#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPPConstructor.generated.h"

UCLASS()
class CPP_BP_API ACPPConstructor : public AActor
{
	GENERATED_BODY()
	
public:	
	//�R���X�g���N�^
	ACPPConstructor();

	//�f�X�g���N�^
	~ACPPConstructor();

protected:
	virtual void BeginPlay() override;

	//Actor�N���X�̏I��������EndPlay�Ŏ�������(Destroy �̖����I�Ȍďo���E���x���ڍs (�V�[�����X�Ȉړ��܂��̓}�b�v�̃��[�h)�ŌĂ΂��)
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:	
	virtual void Tick(float DeltaTime) override;

	// Scene Component
	UPROPERTY(EditAnywhere)
	TObjectPtr<USceneComponent> DefaultSceneRoot;

	// StaticMesh Component
	UPROPERTY(EditAnywhere)
	TObjectPtr<UStaticMeshComponent> StaticMesh;

private:

	// HP
	int hp = 0;
};
