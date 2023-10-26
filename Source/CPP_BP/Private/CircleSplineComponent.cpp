// Fill out your copyright notice in the Description page of Project Settings.


#include "CircleSplineComponent.h"

#if WITH_EDITOR
void UCircleSplineComponent::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	ClearSplinePoints();//�_��������

	for (int32 i = 0; i < PointNum; i++)
	{
		//�_�̈ʒu�̊p�x���v�Z
		double Angle = 2.0 * PI / PointNum * i;

		//�_�̈ʒu���v�Z
		FVector PointLocation = FVector(Radius * sin(Angle), Radius * cos(Angle), 0.0);

		//�_��ǉ�
		AddSplinePointAtIndex(PointLocation, i, ESplineCoordinateSpace::Local, true);
	}

	SetClosedLoop(false, true);//�����X�v���C���ɐݒ�
}
#endif