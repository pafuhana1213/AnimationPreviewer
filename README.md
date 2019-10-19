# EditorUtilityWidget「AnimationPreviewer」

![](https://github.com/pafuhana1213/Screenshot/blob/master/AnimationPreview1.png)  
[![](https://img.youtube.com/vi/KZWN2UZYugA/0.jpg)](https://img.youtube.com/vi/KZWN2UZYugA)

## はじめに
マーケットプレイスで購入した大量のアニメーションをPersonaで確認してリターゲットして…という手順が大変だったので、プレビュー用のエディタ拡張 EditorUtilityWidget「AnimationPreview」を作ってみました。  
Content以下にある全AnimationSequenceアセットを検出した結果をリストで表示し、その項目をクリックすることで自動検出されたSkeletalMeshを用いてアニメーションをプレビューできます。また、指定のSkeletalMeshでプレビューすることが可能です。

## 使い方
1. プロジェクトのPluginsフォルダにAnimationPreviewerフォルダを入れてください

2. 
![](https://github.com/pafuhana1213/Screenshot/blob/master/AnimationPreview2.png)  
AnimationPreviewerPluginのContentにある「EUW_AnimationPreviewer」の右クリックメニュー、
![](https://github.com/pafuhana1213/Screenshot/blob/master/AnimationPreview4.png)  
または Window -> Editor Utility Widgets -> EUW_AnimationPreviewer から起動してください。  
(起動するとプレビュー用のSkeletalMeshActorがレベルに自動配置されます)  

3.   
![](https://github.com/pafuhana1213/Screenshot/blob/master/AnimationPreview5.gif)   
抽出されたアニメーションの項目をクリックするとプレビューを開始します。  

4.   
![](https://github.com/pafuhana1213/Screenshot/blob/master/AnimationPreview6.png)   
特定のSkeletalMeshでプレビューしたい場合は赤枠部分を変更してください。

![](https://github.com/pafuhana1213/Screenshot/blob/master/AnimationPreview7.png)   
なお、指定するAnimationBPのAnimGraphは上図のようになっていることを想定しています。  
/Content/AnimationPreviewSample/AnimBP_AnimationAssetViewerを参考、またはリターゲットしてください。

5.  
![](https://github.com/pafuhana1213/Screenshot/blob/master/AnimationPreview8.gif)     
自動検出プレビューモデルを差し替えたい場合は、ウィンドウ右上にあるリストから変更してください。

## 注意点
- 本プラグインはマーケットプレイスで購入したアニメーションのプレビューを想定して製作されています。そのため、それ以外の用途で使用した場合は不具合が出る可能性があります。その際はお手数ですがその用途に適した形にカスタマイズしてください。

- 自動検出は 「検出されたAnimationSequenceアセットを含むContent直下のフォルダ以下のSkeletamMesh」というルールで現状行っています。

- 指定するプレビューモデルは、自動検出されたSkeletalMeshの各ボーンと同じ名前のボーンを持つSkeletalMeshである必要があります。これはCopy Pose From Meshノードが「ボーン名が同じ場合はTransformをコピーする」という仕様だからです。

## 動作環境
- UE4.23

## ライセンス
MIT

## 作者
[おかず@pafuhana1213](https://twitter.com/pafuhana1213)

## 履歴
2019/10/19 v1.0 公開 v1.0
