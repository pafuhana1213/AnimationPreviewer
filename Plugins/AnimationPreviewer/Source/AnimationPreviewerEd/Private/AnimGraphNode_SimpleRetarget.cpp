// Fill out your copyright notice in the Description page of Project Settings.

#include "AnimGraphNode_SimpleRetarget.h"

#define LOCTEXT_NAMESPACE "AnimGraphNode_SimpleRetarget"

// ----------------------------------------------------------------------------
UAnimGraphNode_SimpleRetarget::UAnimGraphNode_SimpleRetarget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// ----------------------------------------------------------------------------
FText UAnimGraphNode_SimpleRetarget::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
    return LOCTEXT("UAnimGraphNode_SimpleRetarget_Title", "Simple Retarget");
}

#undef LOCTEXT_NAMESPACE