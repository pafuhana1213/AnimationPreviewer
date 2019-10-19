// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AnimGraphNode_Base.h"
#include "AnimNode_SimpleRetarget.h"
#include "AnimGraphNode_SimpleRetarget.generated.h"

UCLASS(MinimalAPI)
class  UAnimGraphNode_SimpleRetarget : public UAnimGraphNode_Base
{
	GENERATED_UCLASS_BODY()
	
	
    UPROPERTY(EditAnywhere, Category = Settings)
    FAnimNode_SimpleRetarget Node;

public:
    virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;

};
