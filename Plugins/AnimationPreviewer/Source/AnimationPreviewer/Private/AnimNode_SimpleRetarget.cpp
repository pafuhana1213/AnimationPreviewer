#include "AnimNode_SimpleRetarget.h"
#include "AnimationRuntime.h"
#include "Animation/AnimInstanceProxy.h"

FAnimNode_SimpleRetarget::FAnimNode_SimpleRetarget()
{
}
void FAnimNode_SimpleRetarget::Initialize_AnyThread(const FAnimationInitializeContext& Context)
{
	FAnimNode_Base::Initialize_AnyThread(Context);
}

void FAnimNode_SimpleRetarget::CacheBones_AnyThread(const FAnimationCacheBonesContext& Context)
{
	FAnimNode_Base::CacheBones_AnyThread(Context);

}

void FAnimNode_SimpleRetarget::Evaluate_AnyThread(FPoseContext& Output)
{
	SourcePose.Evaluate(Output);

	FCompactPose& OutPose = Output.Pose;
	const FBoneContainer& BoneContainer = OutPose.GetBoneContainer();
	auto& RefSkeleton = BoneContainer.GetReferenceSkeleton();
	auto SkeletonAsset = BoneContainer.GetSkeletonAsset();
	for (const FCompactPoseBoneIndex PoseBoneIndex : OutPose.ForEachBoneIndex())
	{
		switch (SkeletonAsset->GetBoneTranslationRetargetingMode( BoneContainer.GetSkeletonIndex(PoseBoneIndex) ))
		{
		case EBoneTranslationRetargetingMode::Animation:
		case EBoneTranslationRetargetingMode::AnimationScaled:
		case EBoneTranslationRetargetingMode::AnimationRelative:
		case EBoneTranslationRetargetingMode::OrientAndScale:
			//UE_LOG(LogTemp, Warning, TEXT("Other : %s"), *RefSkeleton.GetBoneName(PoseBoneIndex.GetInt()).ToString());
			continue;

		case EBoneTranslationRetargetingMode::Skeleton:
			const FTransform& RefPoseTM = RefSkeleton.GetRefBonePose()[PoseBoneIndex.GetInt()];
			OutPose[PoseBoneIndex].SetLocation(RefPoseTM.GetLocation());
			//UE_LOG(LogTemp, Warning, TEXT("Skeleton : %s"), *RefSkeleton.GetBoneName(PoseBoneIndex.GetInt()).ToString());
			continue;
		}
	}
}