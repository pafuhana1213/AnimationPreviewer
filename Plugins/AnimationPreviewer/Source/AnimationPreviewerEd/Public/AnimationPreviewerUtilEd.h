// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AnimationPreviewerUtilEd.generated.h"

/**
 * 
 */
UCLASS()
class ANIMATIONPREVIEWERED_API UAnimationPreviewerUtilEd : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable)
	static void RetargetAnimations(USkeleton* NewSkeleton, const TArray< UAnimSequence*> AssetsToRetarget, bool bDuplicateAsset, bool bRemapReferencedAssets, bool bAllowRemapToExisting, bool bConvertSpaces);
};
