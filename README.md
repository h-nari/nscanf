# nscanf

sscanf関数のサブセット

## 開発の動機

Arduino環境でプログラムをしていて、sscanf関数が使えず、数値を含む文字列の解釈に手間取るので、sscanfのサブセットを作成しました。

## サポートしている形式

* %d  整数 (int)
* %f 浮動小数点(float)

## 使用例

<pre>
 int yy,mm,dd;
 int r = nscanf("2016/11/18",&yy,&mm,&dd)
</pre>

## 使用方法

nscanf.cとnscanf.hをコピーしてお使いください。
Makefileとmain.cは Linux環境等でプログラムのテストを行う際に使用します。

## その他

gcc用にformat attributeでscanfを指定していますので、引数型に誤りがあればgccが警告を出してくれるはずです。
