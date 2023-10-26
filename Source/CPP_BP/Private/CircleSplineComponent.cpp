// Fill out your copyright notice in the Description page of Project Settings.


#include "CircleSplineComponent.h"

#if WITH_EDITOR
void UCircleSplineComponent::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	ClearSplinePoints();//点を初期化

	for (int32 i = 0; i < PointNum; i++)
	{
		//点の位置の角度を計算
		double Angle = 2.0 * PI / PointNum * i;

		//点の位置を計算
		FVector PointLocation = FVector(Radius * sin(Angle), Radius * cos(Angle), 0.0);

		//点を追加
		AddSplinePointAtIndex(PointLocation, i, ESplineCoordinateSpace::Local, true);
	}

	SetClosedLoop(false, true);//閉じたスプラインに設定
}
#endif