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

	//Init関数では同じ値を数指定で初期値を設定できます。
	FruitsLocal.Init(TEXT("Apple"), 3);
	// C++版のFor Each Loop
	for (FString Message : FruitsLocal)
	{
		// Messagesの値を出力する
		UKismetSystemLibrary::PrintString(this, Message, true, true, FColor::Green, 20.0f, TEXT("None"));
	}

	//「Add」、「Emplace」は配列に値を追加します。
	Fruits.Add(TEXT("Orange"));
	Fruits.Emplace(TEXT("Grape"));
	// C++版のFor Each Loop
	for (FString Message : Fruits)
	{
		// Messagesの値を出力する
		UKismetSystemLibrary::PrintString(this, Message, true, true, FColor::Blue, 20.0f, TEXT("None"));
	}
	
	//「AppendUnique」は重複しないように追加します。
	Fruits2.AddUnique(TEXT("Orange")); // 追加
	Fruits2.AddUnique(TEXT("Apple"));  // 重複するので追加されない
	// C++版のFor Each Loop
	for (FString Message : Fruits2)
	{
		// Messagesの値を出力する
		UKismetSystemLibrary::PrintString(this, Message, true, true, FColor::Orange, 20.0f, TEXT("None"));
	}

	//「Append」は配列の末尾に配列を追加できます。
	//「 += 」演算子でもAppendと同様に配列を追加できます。
	// 配列を追加
	Fruits3.Append(Vegetables);
	// 配列を追加
	//Fruits += Vegetables;
	// C++版のFor Each Loop
	for (FString Message : Fruits3)
	{
		// Messagesの値を出力する
		UKismetSystemLibrary::PrintString(this, Message, true, true, FColor::Magenta, 20.0f, TEXT("None"));
	}

	//「Insert」ノードは指定したIndexにElementを挿入します。
	Fruits3.Insert(TEXT("Orange"), 1);
	// C++版のFor Each Loop
	for (FString Message : Fruits3)
	{
		// Messagesの値を出力する
		UKismetSystemLibrary::PrintString(this, Message, true, true, FColor::Yellow, 20.0f, TEXT("None"));
	}

	//「SetNum」は指定した数値で初期化した値のElementを数値分追加します。(空白行が追加される)
	Fruits.SetNum(5);
	// C++版のFor Each Loop
	for (FString Message : Fruits)
	{
		// Messagesの値を出力する
		UKismetSystemLibrary::PrintString(this, Message, true, true, FColor::Cyan, 20.0f, TEXT("None"));
	}

	//配列数より少ない値を指定した場合は指定した配列数に修正します。
	Fruits.SetNum(1);
	// C++版のFor Each Loop
	for (FString Message : Fruits)
	{
		// Messagesの値を出力する
		UKismetSystemLibrary::PrintString(this, Message, true, true, FColor::Silver, 20.0f, TEXT("None"));
	}

	//「演算子[]」を使って要素を取得します。
	FString Fruit = Fruits2[1];
	UKismetSystemLibrary::PrintString(this, Fruit, true, true, FColor::Red, 20.0f, TEXT("None"));

	//「GetData」は配列のポインタを返せます。
	FString* FruitPtr = Fruits.GetData();

	//UE C++ で int32 型を FString 型に変換するには、以下のようにします。
	int32 Value = 123;
	FString String = FString::FromInt(Value);
	
	//FString 型を int32 型に変換するには、以下のようにします。
	FString String2 = "123";
	int32 Value2 = FCString::Atoi(*String);

	//「Num」は配列の要素数を取得します。
	int32 Count = Fruits2.Num();
	FString CountMessage = FString::FromInt(Count);
	UKismetSystemLibrary::PrintString(this, CountMessage, true, true, FColor::Black, 20.0f, TEXT("None"));
	
	//「GetTypeSize」は要素の型のサイズを取得できます。
	uint32 ElementSize = Fruits.GetTypeSize();
	// uint32 VariableTypeSize = sizeof(FString);
	FString String3 = FString::FromInt(ElementSize);
	UKismetSystemLibrary::PrintString(this, String3, true, true, FColor::White, 20.0f, TEXT("None"));

	//[Last]、[Top]は配列の要素の最後を取得できます。
	//Fruits2.Last();
	UKismetSystemLibrary::PrintString(this, Fruits2.Last(), true, true, FColor::Blue, 20.0f, TEXT("None"));
	//[Last]はIndexを指定すると後ろからのIndex指定になります。
	FString aa = Fruits2.Last(1);
	UKismetSystemLibrary::PrintString(this, aa, true, true, FColor::Magenta, 20.0f, TEXT("None"));
	FString bb = Fruits2.Top();
	UKismetSystemLibrary::PrintString(this, bb, true, true, FColor::Yellow, 20.0f, TEXT("None"));
	FString cc = Fruits2[0];
	UKismetSystemLibrary::PrintString(this, cc, true, true, FColor::Yellow, 20.0f, TEXT("None"));

	//配列の先頭から順番にローカル変数に値を入れて配列数分loopを回します。
	for (FString Fruit2 : Fruits2)
	{
		UKismetSystemLibrary::PrintString(this, Fruit2,true, true, FColor::Cyan, 20.0f);
	}

	//Indexの数を増やしながらIndexのElementを取得してloopを回します。
	for (int32 Index = 0; Index < Fruits3.Num(); ++Index)
	{
		UKismetSystemLibrary::PrintString(this, Fruits3[Index], true, true, FColor::Silver, 20.0f);
	}

	//「演算子[]」を使って要素を設定します。
	Fruits[0] = TEXT("AAA");
	for (FString Fruit3 : Fruits)
	{
		UKismetSystemLibrary::PrintString(this, Fruit3, true, true, FColor::Red, 20.0f);
	}

	//[Empty]は配列のすべてのElementを消去します。
	Fruits.Empty();
	for (FString Fruit4 : Fruits)
	{
		UKismetSystemLibrary::PrintString(this, Fruit4, true, true, FColor::Blue, 20.0f);
	}

	//[Remove]ノードは指定した値と一致するElementを削除します。
	//一致する値が複数ある場合は一致した値のElementを削除します。
	Fruits2.Remove(TEXT("Apple"));
	for (FString Fruit5 : Fruits2)
	{
		UKismetSystemLibrary::PrintString(this, Fruit5, true, true, FColor::Cyan, 20.0f);
	}

	//[RemoveSingle]ノードは先頭から一番近い指定した値と一致するElementを削除します。
	for (FString Fruit6 : Fruits4)
	{
		UKismetSystemLibrary::PrintString(this, Fruit6, true, true, FColor::Red, 20.0f);
	}
	Fruits4.RemoveSingle(TEXT("Apple"));
	for (FString Fruit7 : Fruits4)
	{
		UKismetSystemLibrary::PrintString(this, Fruit7, true, true, FColor::Green, 20.0f);
	}

	//[RemoveAt]は指定したIndexのElementを削除します。
	Fruits4.RemoveAt(1);//Bananaを消す
	for (FString Fruit8 : Fruits4)
	{
		UKismetSystemLibrary::PrintString(this, Fruit8, true, true, FColor::Yellow, 20.0f);
	}

	//「IsValidIndex」は指定したIndexが有効か無効を調べられます。
	bool bValidM1 = Fruits4.IsValidIndex(-1);// bValidM1 == false;
	FString str = bValidM1 ? TEXT("true") : TEXT("false");
	UKismetSystemLibrary::PrintString(this, str, true, true, FColor::Blue, 20.0f);
	bool bValid0 = Fruits4.IsValidIndex(0);// bValid0  == true;
	FString str2 = bValid0 ? TEXT("true") : TEXT("false");
	UKismetSystemLibrary::PrintString(this, str2, true, true, FColor::Red, 20.0f);
	bool bValid5 = Fruits4.IsValidIndex(5);// bValid5  == false;
	FString str3 = bValid5 ? TEXT("true") : TEXT("false");
	UKismetSystemLibrary::PrintString(this, str3, true, true, FColor::Blue, 20.0f);

	//「Contains」は指定した値が配列のElementに含まれるか調べられます。
	bool bApple = Fruits4.Contains(TEXT("Apple"));// bApple  == true;
	FString str5 = bApple ? TEXT("true") : TEXT("false");
	UKismetSystemLibrary::PrintString(this, str5, true, true, FColor::Red, 20.0f);
	bool bOrange = Fruits4.Contains(TEXT("Orange"));// bOrange == false;
	FString str4 = bOrange ? TEXT("true") : TEXT("false");
	UKismetSystemLibrary::PrintString(this, str4, true, true, FColor::Blue, 20.0f);

	//「ContainsByPredicate」は特定の条件が含まれるかを調べられます。
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

	//「Find」は配列の先頭から指定した値と一致するIndexを取得します。
	//「FindLast」は配列の最後尾から指定した値と一致するIndexを取得します。
	//「Find」、「FindLast」が値を見つけられなかった時は「 - 1（INDEX_NONE）」を返します。
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

	//「IndexOfByKey」は最初に検出された要素のインデックスを返し、見つからなかったら「-1（INDEX_NONE）」を返します。
	int32 Index2 = Fruits5.IndexOfByKey(TEXT("Apple"));
	FString String13 = FString::FromInt(Index2);
	UKismetSystemLibrary::PrintString(this, String13, true, true, FColor::Yellow, 20.0f);

	//「IndexOfByPredicate」は指定した条件と一致した値のIndexを返し、見つからなかったら「-1（INDEX_NONE）」を返します。
	int32 Index30 = Fruits5.IndexOfByPredicate([](const FString& Str30) 
	{
		return Str30.Contains(TEXT("Lemon"));
	});
	FString String30 = FString::FromInt(Index30);
	UKismetSystemLibrary::PrintString(this, String30, true, true, FColor::Black, 20.0f);

	//「FindByKey」は値と一致したElementのポインタを返し、見つからなかったら「nullptr」を返します。
	FString* LemonPtr = Fruits5.FindByKey(TEXT("Lemon"));
	FString newStr = *LemonPtr;
	UKismetSystemLibrary::PrintString(this, newStr, true, true, FColor::Red, 20.0f);

	FString* OrangePtr = Fruits5.FindByKey(TEXT("Orange"));


	//「FindByPredicate」は指定した条件と一致した値のポインタを返し、見つからなかったら「nullptr」を返します。
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

	//「Sort」では昇順に配列を入れ替えます。
	//SortArray.Sort();
	//// C++版のFor Each Loop
	//for (FString Message : SortArray)
	//{
	//	// Messagesの値を出力する
	//	UKismetSystemLibrary::PrintString(this, Message, true, true, FColor::Cyan, 20.0f, TEXT("None"));
	//}

	// 文字数が少ない順にSortする
	//SortArray.Sort([](const FString& A, const FString& B)
	//{
	//	return A.Len() < B.Len();
	//});
	//// C++版のFor Each Loop
	//for (FString Message : SortArray)
	//{
	//	// Messagesの値を出力する
	//	UKismetSystemLibrary::PrintString(this, Message, true, true, FColor::Silver, 20.0f, TEXT("None"));
	//}

	// 文字数が少ない順にSortする
	//SortArray.HeapSort([](const FString& A, const FString& B)
	//{
	//	return A.Len() < B.Len();
	//});
	//// C++版のFor Each Loop
	//for (FString Message : SortArray)
	//{
	//	// Messagesの値を出力する
	//	UKismetSystemLibrary::PrintString(this, Message, true, true, FColor::Silver, 20.0f, TEXT("None"));
	//}

	//「StableSort」はステイブルソートを実行します。（相対順序が保証されます）
	// 文字数が少ない順にSortする
	SortArray.StableSort([](const FString& A, const FString& B)
	{
		return A.Len() < B.Len();
	});
	// C++版のFor Each Loop
	for (FString Message : SortArray)
	{
		// Messagesの値を出力する
		UKismetSystemLibrary::PrintString(this, Message, true, true, FColor::Silver, 20.0f, TEXT("None"));
	}
}

void ACPPArray2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

