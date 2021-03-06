# Scroll bar for openFrameworks

(C) 2016- H.Hiro <main@hhiro.net>

<img src="screenshot.png" alt="Screenshot" />

## Overview

This program provides scroll bars for [openFrameworks](http://openframeworks.cc/ "openFrameworks"): C++-based multi-platform graphical software library.

## Try the sample

This sample is for Visual C++ 2015; Visual-C++-specific code is included only for selecting picture files (built-in `ofSystemLoadDialog` cannot give correct file name if it includes non-ASCII characters). To try this,

1.  Follow [the instruction for setting up visual studio 2015 for openFrameworks](http://openframeworks.cc/setup/vs/ "visual studio | openFrameworks"). You will find three files: `main.cpp`, `ofApp.cpp` and `ofApp.h`.
2.  Replace them with the files in the repository, and put `ScrollBar4OF.hpp` together with them (in the same folder).
3.  Run the program.

## How to use

Sorry for not preparing the detailed document. See the sample code at first.

### Methods for openFrameworks events

An important point is that the following methods for the scroll bars should be invoked in `ofApp::[The same method name]`:

-   `mousePressed`
-   `mouseDragged`
-   `mouseReleased`
-   `update`
-   `draw`

### Using hook functions

To conduct some actions whenever the value of a scroll bar is changed, see the examples in `ofApp::setup`. One way is to implement a class inheriting `[Scroll bar type]::ScrollBarHook` and overriding a method `action`; the other is to set a lambda expression (if available; uncomment `//#define SCROLLBAR4OF_CPP11_STD_FUNCTION` in `ScrollBar4OF.hpp`).

## LICENSE

Released under the MIT License. See `LICENSE` file for the full text.

# openFrameworks用スクロールバー

<img src="screenshot.png" alt="Screenshot" />

## 概要

[openFrameworks](http://openframeworks.cc/ "openFrameworks")（C++ベース・マルチプラットフォームなグラフィカルソフトのためのライブラリ）で利用するためのスクロールバーです。

## 試す

サンプルはVisual C++ 2015向けのみ作っています。なお、Visual C++に特化したコードは、画像ファイルを選択する部分のみです（`ofSystemLoadDialog`という組み込みの関数もありますが、非ASCII文字のファイル名を正しく扱えないという問題があるため使っていません）。これを試すには以下のようにしてください。

1.  [openFrameworksのVisual Studio 2015向けセットアップ（英語）](http://openframeworks.cc/setup/vs/ "visual studio | openFrameworks")の手順に従って準備をします。このとき、`main.cpp`・`ofApp.cpp`・`ofApp.h`の3つのファイルができます。
2.  上記の3つのファイルを、当レポジトリにあるファイルで置き換えます。さらに、`ScrollBar4OF.hpp`も同じフォルダに一緒に置きます。
3.  プログラムを実行します。

## 使い方

恐れ入りますが、詳細なドキュメントは用意していません。サンプルコードをまずご覧いただければと思います。

### openFrameworksのイベントのためのメソッド

重要な点として、スクロールバーの以下のメソッドを、`ofApp::[同名のメソッド]`で呼ぶ必要があります。

-   `mousePressed`
-   `mouseDragged`
-   `mouseReleased`
-   `update`
-   `draw`

### フック関数を使う

スクロールバーの値が変化するたびに行いたい処理がある場合については、`ofApp::setup`内のサンプルをご覧ください。「`[スクロールバーの型]::ScrollBarHook`クラスを継承して`action`メソッドをオーバーライドする方法と、（利用できるなら）ラムダ式を用いる方法（`ScrollBar4OF.hpp`内の`//#define SCROLLBAR4OF_CPP11_STD_FUNCTION`をコメントアウトを解除する必要あり）があります。

## ライセンス

MIT Licenseで提供します。本文（英語）は「LICENSE」ファイルをご覧ください。
