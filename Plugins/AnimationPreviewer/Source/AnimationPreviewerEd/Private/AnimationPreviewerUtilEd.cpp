// Fill out your copyright notice in the Description page of Project Settings.

#include "AnimationPreviewerUtilEd.h"
#include "AssetData.h"
#include "EditorAnimUtils.h"




void UAnimationPreviewerUtilEd::RetargetAnimations(USkeleton* NewSkeleton, const TArray< UAnimSequence*> AssetsToRetarget, bool bDuplicateAsset, bool bRemapReferencedAssets, bool bAllowRemapToExisting, bool bConvertSpaces)
{
	if (!NewSkeleton || AssetsToRetarget.Num() == 0)
	{
		return ;
	}

	TArray<TWeakObjectPtr<UObject>> ObjectToRetarget;
	for (UAnimSequence* AnimSequence : AssetsToRetarget)
	{
		ObjectToRetarget.Empty();
		ObjectToRetarget.Add(AnimSequence);

		if (bDuplicateAsset)
		{
			EditorAnimUtils::FNameDuplicationRule NameDuplicateRule;
			EditorAnimUtils::RetargetAnimations(AnimSequence->GetSkeleton(), NewSkeleton, ObjectToRetarget, bRemapReferencedAssets, &NameDuplicateRule, bConvertSpaces);
		}
		else 
		{
			EditorAnimUtils::RetargetAnimations(AnimSequence->GetSkeleton(), NewSkeleton, ObjectToRetarget, bRemapReferencedAssets, nullptr, bConvertSpaces);
		}
	}
};
