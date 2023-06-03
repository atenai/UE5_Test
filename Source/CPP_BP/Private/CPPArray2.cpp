// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPArray2.h"
#include "Kismet/KismetSystemLibrary.h"

ACPPArray2::ACPPArray2()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ACPPArray2::BeginPlay()
{
	Super::BeginPlay();

	//Init�֐��ł͓����l�𐔎w��ŏ����l��ݒ�ł��܂��B
	FruitsLocal.Init(TEXT("Apple"), 3);
	// C++�ł�For Each Loop
	for (FString Message : FruitsLocal)
	{
		// Messages�̒l���o�͂���
		UKismetSystemLibrary::PrintString(this, Message, true, true, FColor::Green, 20.0f, TEXT("None"));
	}

	//�uAdd�v�A�uEmplace�v�͔z��ɒl��ǉ����܂��B
	Fruits.Add(TEXT("Orange"));
	Fruits.Emplace(TEXT("Grape"));
	// C++�ł�For Each Loop
	for (FString Message : Fruits)
	{
		// Messages�̒l���o�͂���
		UKismetSystemLibrary::PrintString(this, Message, true, true, FColor::Blue, 20.0f, TEXT("None"));
	}
	
	//�uAppendUnique�v�͏d�����Ȃ��悤�ɒǉ����܂��B
	Fruits2.AddUnique(TEXT("Orange")); // �ǉ�
	Fruits2.AddUnique(TEXT("Apple"));  // �d������̂Œǉ�����Ȃ�
	// C++�ł�For Each Loop
	for (FString Message : Fruits2)
	{
		// Messages�̒l���o�͂���
		UKismetSystemLibrary::PrintString(this, Message, true, true, FColor::Orange, 20.0f, TEXT("None"));
	}

	//�uAppend�v�͔z��̖����ɔz���ǉ��ł��܂��B
	//�u += �v���Z�q�ł�Append�Ɠ��l�ɔz���ǉ��ł��܂��B
	// �z���ǉ�
	Fruits3.Append(Vegetables);
	// �z���ǉ�
	//Fruits += Vegetables;
	// C++�ł�For Each Loop
	for (FString Message : Fruits3)
	{
		// Messages�̒l���o�͂���
		UKismetSystemLibrary::PrintString(this, Message, true, true, FColor::Magenta, 20.0f, TEXT("None"));
	}

	//�uInsert�v�m�[�h�͎w�肵��Index��Element��}�����܂��B
	Fruits3.Insert(TEXT("Orange"), 1);
	// C++�ł�For Each Loop
	for (FString Message : Fruits3)
	{
		// Messages�̒l���o�͂���
		UKismetSystemLibrary::PrintString(this, Message, true, true, FColor::Yellow, 20.0f, TEXT("None"));
	}

	//�uSetNum�v�͎w�肵�����l�ŏ����������l��Element�𐔒l���ǉ����܂��B(�󔒍s���ǉ������)
	Fruits.SetNum(5);
	// C++�ł�For Each Loop
	for (FString Message : Fruits)
	{
		// Messages�̒l���o�͂���
		UKismetSystemLibrary::PrintString(this, Message, true, true, FColor::Cyan, 20.0f, TEXT("None"));
	}

	//�z�񐔂�菭�Ȃ��l���w�肵���ꍇ�͎w�肵���z�񐔂ɏC�����܂��B
	Fruits.SetNum(1);
	// C++�ł�For Each Loop
	for (FString Message : Fruits)
	{
		// Messages�̒l���o�͂���
		UKismetSystemLibrary::PrintString(this, Message, true, true, FColor::Silver, 20.0f, TEXT("None"));
	}

	//�u���Z�q[]�v���g���ėv�f���擾���܂��B
	FString Fruit = Fruits2[1];
	UKismetSystemLibrary::PrintString(this, Fruit, true, true, FColor::Red, 20.0f, TEXT("None"));

	//�uGetData�v�͔z��̃|�C���^��Ԃ��܂��B
	FString* FruitPtr = Fruits.GetData();

	//UE C++ �� int32 �^�� FString �^�ɕϊ�����ɂ́A�ȉ��̂悤�ɂ��܂��B
	int32 Value = 123;
	FString String = FString::FromInt(Value);
	
	//FString �^�� int32 �^�ɕϊ�����ɂ́A�ȉ��̂悤�ɂ��܂��B
	FString String2 = "123";
	int32 Value2 = FCString::Atoi(*String);

	//�uNum�v�͔z��̗v�f�����擾���܂��B
	int32 Count = Fruits2.Num();
	FString CountMessage = FString::FromInt(Count);
	UKismetSystemLibrary::PrintString(this, CountMessage, true, true, FColor::Black, 20.0f, TEXT("None"));
	
	//�uGetTypeSize�v�͗v�f�̌^�̃T�C�Y���擾�ł��܂��B
	uint32 ElementSize = Fruits.GetTypeSize();
	// uint32 VariableTypeSize = sizeof(FString);
	FString String3 = FString::FromInt(ElementSize);
	UKismetSystemLibrary::PrintString(this, String3, true, true, FColor::White, 20.0f, TEXT("None"));

	//[Last]�A[Top]�͔z��̗v�f�̍Ō���擾�ł��܂��B
	//Fruits2.Last();
	UKismetSystemLibrary::PrintString(this, Fruits2.Last(), true, true, FColor::Blue, 20.0f, TEXT("None"));
	//[Last]��Index���w�肷��ƌ�납���Index�w��ɂȂ�܂��B
	FString aa = Fruits2.Last(1);
	UKismetSystemLibrary::PrintString(this, aa, true, true, FColor::Magenta, 20.0f, TEXT("None"));
	FString bb = Fruits2.Top();
	UKismetSystemLibrary::PrintString(this, bb, true, true, FColor::Yellow, 20.0f, TEXT("None"));
	FString cc = Fruits2[0];
	UKismetSystemLibrary::PrintString(this, cc, true, true, FColor::Yellow, 20.0f, TEXT("None"));

	//�z��̐擪���珇�ԂɃ��[�J���ϐ��ɒl�����Ĕz�񐔕�loop���񂵂܂��B
	for (FString Fruit2 : Fruits2)
	{
		UKismetSystemLibrary::PrintString(this, Fruit2,true, true, FColor::Cyan, 20.0f);
	}

	//Index�̐��𑝂₵�Ȃ���Index��Element���擾����loop���񂵂܂��B
	for (int32 Index = 0; Index < Fruits3.Num(); ++Index)
	{
		UKismetSystemLibrary::PrintString(this, Fruits3[Index], true, true, FColor::Silver, 20.0f);
	}

	//�u���Z�q[]�v���g���ėv�f��ݒ肵�܂��B
	Fruits[0] = TEXT("AAA");
	for (FString Fruit3 : Fruits)
	{
		UKismetSystemLibrary::PrintString(this, Fruit3, true, true, FColor::Red, 20.0f);
	}

	//[Empty]�͔z��̂��ׂĂ�Element���������܂��B
	Fruits.Empty();
	for (FString Fruit4 : Fruits)
	{
		UKismetSystemLibrary::PrintString(this, Fruit4, true, true, FColor::Blue, 20.0f);
	}

	//[Remove]�m�[�h�͎w�肵���l�ƈ�v����Element���폜���܂��B
	//��v����l����������ꍇ�͈�v�����l��Element���폜���܂��B
	Fruits2.Remove(TEXT("Apple"));
	for (FString Fruit5 : Fruits2)
	{
		UKismetSystemLibrary::PrintString(this, Fruit5, true, true, FColor::Cyan, 20.0f);
	}

	//[RemoveSingle]�m�[�h�͐擪�����ԋ߂��w�肵���l�ƈ�v����Element���폜���܂��B
	for (FString Fruit6 : Fruits4)
	{
		UKismetSystemLibrary::PrintString(this, Fruit6, true, true, FColor::Red, 20.0f);
	}
	Fruits4.RemoveSingle(TEXT("Apple"));
	for (FString Fruit7 : Fruits4)
	{
		UKismetSystemLibrary::PrintString(this, Fruit7, true, true, FColor::Green, 20.0f);
	}

	//[RemoveAt]�͎w�肵��Index��Element���폜���܂��B
	Fruits4.RemoveAt(1);//Banana������
	for (FString Fruit8 : Fruits4)
	{
		UKismetSystemLibrary::PrintString(this, Fruit8, true, true, FColor::Yellow, 20.0f);
	}

	//�uIsValidIndex�v�͎w�肵��Index���L���������𒲂ׂ��܂��B
	bool bValidM1 = Fruits4.IsValidIndex(-1);// bValidM1 == false;
	FString str = bValidM1 ? TEXT("true") : TEXT("false");
	UKismetSystemLibrary::PrintString(this, str, true, true, FColor::Blue, 20.0f);
	bool bValid0 = Fruits4.IsValidIndex(0);// bValid0  == true;
	FString str2 = bValid0 ? TEXT("true") : TEXT("false");
	UKismetSystemLibrary::PrintString(this, str2, true, true, FColor::Red, 20.0f);
	bool bValid5 = Fruits4.IsValidIndex(5);// bValid5  == false;
	FString str3 = bValid5 ? TEXT("true") : TEXT("false");
	UKismetSystemLibrary::PrintString(this, str3, true, true, FColor::Blue, 20.0f);

	//�uContains�v�͎w�肵���l���z���Element�Ɋ܂܂�邩���ׂ��܂��B
	bool bApple = Fruits4.Contains(TEXT("Apple"));// bApple  == true;
	FString str5 = bApple ? TEXT("true") : TEXT("false");
	UKismetSystemLibrary::PrintString(this, str5, true, true, FColor::Red, 20.0f);
	bool bOrange = Fruits4.Contains(TEXT("Orange"));// bOrange == false;
	FString str4 = bOrange ? TEXT("true") : TEXT("false");
	UKismetSystemLibrary::PrintString(this, str4, true, true, FColor::Blue, 20.0f);

	//�uContainsByPredicate�v�͓���̏������܂܂�邩�𒲂ׂ��܂��B
	bool bLen6 = Fruits3.ContainsByPredicate([](const FString& Str6)
	{
		return Str6.Len() == 6;
	});
	FString str8 = bLen6 ? TEXT("true") : TEXT("false");
	UKismetSystemLibrary::PrintString(this, str8, true, true, FColor::Red, 20.0f);
	bool bLen7 = Fruits3.ContainsByPredicate([](const FString& Str7)
	{
		return Str7.Len() == 7;
	});
	FString str9 = bLen7 ? TEXT("true") : TEXT("false");
	UKismetSystemLibrary::PrintString(this, str9, true, true, FColor::Blue, 20.0f);

	//�uFind�v�͔z��̐擪����w�肵���l�ƈ�v����Index���擾���܂��B
	//�uFindLast�v�͔z��̍Ō������w�肵���l�ƈ�v����Index���擾���܂��B
	//�uFind�v�A�uFindLast�v���l���������Ȃ��������́u - 1�iINDEX_NONE�j�v��Ԃ��܂��B
	int32 Index;
	Fruits5.Find(TEXT("Apple"), Index);
	FString String10 = FString::FromInt(Index);
	UKismetSystemLibrary::PrintString(this, String10, true, true, FColor::Orange, 20.0f);
	int32 IndexLast;
	Fruits5.FindLast(TEXT("Apple"), IndexLast);
	FString String11 = FString::FromInt(IndexLast);
	UKismetSystemLibrary::PrintString(this, String11, true, true, FColor::Purple, 20.0f);
	int32 IndexNothing;
	Fruits5.Find(TEXT("Orange"), IndexNothing);
	FString String12 = FString::FromInt(IndexNothing);
	UKismetSystemLibrary::PrintString(this, String12, true, true, FColor::Magenta, 20.0f);

	//�uIndexOfByKey�v�͍ŏ��Ɍ��o���ꂽ�v�f�̃C���f�b�N�X��Ԃ��A������Ȃ�������u-1�iINDEX_NONE�j�v��Ԃ��܂��B
	int32 Index2 = Fruits5.IndexOfByKey(TEXT("Apple"));
	FString String13 = FString::FromInt(Index2);
	UKismetSystemLibrary::PrintString(this, String13, true, true, FColor::Yellow, 20.0f);

	//�uIndexOfByPredicate�v�͎w�肵�������ƈ�v�����l��Index��Ԃ��A������Ȃ�������u-1�iINDEX_NONE�j�v��Ԃ��܂��B
	int32 Index30 = Fruits5.IndexOfByPredicate([](const FString& Str30) 
	{
		return Str30.Contains(TEXT("Lemon"));
	});
	FString String30 = FString::FromInt(Index30);
	UKismetSystemLibrary::PrintString(this, String30, true, true, FColor::Black, 20.0f);

	//�uFindByKey�v�͒l�ƈ�v����Element�̃|�C���^��Ԃ��A������Ȃ�������unullptr�v��Ԃ��܂��B
	FString* LemonPtr = Fruits5.FindByKey(TEXT("Lemon"));
	FString newStr = *LemonPtr;
	UKismetSystemLibrary::PrintString(this, newStr, true, true, FColor::Red, 20.0f);

	FString* OrangePtr = Fruits5.FindByKey(TEXT("Orange"));


	//�uFindByPredicate�v�͎w�肵�������ƈ�v�����l�̃|�C���^��Ԃ��A������Ȃ�������unullptr�v��Ԃ��܂��B
	FString* LemonPtr40 = Fruits5.FindByPredicate([](const FString& Str40)
	{
		return Str40.Contains(TEXT("Lemon"));
	});
	FString newStr50 = *LemonPtr40;
	UKismetSystemLibrary::PrintString(this, newStr50, true, true, FColor::Red, 20.0f);
	FString* OrangePtr50 = Fruits5.FindByPredicate([](const FString& Str50)
	{
		return Str50.Contains(TEXT("Orange"));
	});

	//�uSort�v�ł͏����ɔz������ւ��܂��B
	//SortArray.Sort();
	//// C++�ł�For Each Loop
	//for (FString Message : SortArray)
	//{
	//	// Messages�̒l���o�͂���
	//	UKismetSystemLibrary::PrintString(this, Message, true, true, FColor::Cyan, 20.0f, TEXT("None"));
	//}

	// �����������Ȃ�����Sort����
	//SortArray.Sort([](const FString& A, const FString& B)
	//{
	//	return A.Len() < B.Len();
	//});
	//// C++�ł�For Each Loop
	//for (FString Message : SortArray)
	//{
	//	// Messages�̒l���o�͂���
	//	UKismetSystemLibrary::PrintString(this, Message, true, true, FColor::Silver, 20.0f, TEXT("None"));
	//}

	// �����������Ȃ�����Sort����
	//SortArray.HeapSort([](const FString& A, const FString& B)
	//{
	//	return A.Len() < B.Len();
	//});
	//// C++�ł�For Each Loop
	//for (FString Message : SortArray)
	//{
	//	// Messages�̒l���o�͂���
	//	UKismetSystemLibrary::PrintString(this, Message, true, true, FColor::Silver, 20.0f, TEXT("None"));
	//}

	//�uStableSort�v�̓X�e�C�u���\�[�g�����s���܂��B�i���Ώ������ۏ؂���܂��j
	// �����������Ȃ�����Sort����
	SortArray.StableSort([](const FString& A, const FString& B)
	{
		return A.Len() < B.Len();
	});
	// C++�ł�For Each Loop
	for (FString Message : SortArray)
	{
		// Messages�̒l���o�͂���
		UKismetSystemLibrary::PrintString(this, Message, true, true, FColor::Silver, 20.0f, TEXT("None"));
	}
}

void ACPPArray2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

