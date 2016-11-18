# nscanf

sscanf関数のサブセット

## 開発の動機

Arduino環境でプログラムをしていて、sscanf関数が使えず、数値を含む文字列の解釈に手間取るので、sscanfのサブセットを作成しました。

## サポートしている形式

* %d  整数 (int)
* %x  16進数
* %f,%e,%g 浮動小数点(float)

## 使用例

<pre>
 int yy,mm,dd;
 int r = nscanf("2016/11/18",&yy,&mm,&dd)
</pre>


## インストール方法

nscanf.cとnscanf.hをコピーしてお使いください。
Makefileとmain.cは Linux環境等でプログラムのテストを行う際に使用します。

## コンパイル時の引数チェック

gcc用にformat attributeでscanfを指定していますので、引数型に誤りがあればgccが警告を出してくれるはずです。


## 拡張機能

フォーマット文字列に、文字列の最後にマッチする文字 フォームフィード(\f)を追加しました。次のように使用します。スキャンする文字列に余分な文字列がないことを確認できます。

<pre>
int a,b,c,d;
a = nscanf("123b","%d\f", b);
c = nscanf("456","%d\f", d);
printf("a:%d b:%d c:%d d:%d\n",a,b,c,d);
</pre>
出力は以下のようになります。
<pre>
a:1 b:123 c:2 d:456
</pre>

文字列の最後にマッチする文字の前には%を付けたいところですが、そうするとformat attributeのチェックで警告が出てしまいます。 \fは空白文字ですのでsscanfでは無視されます。よってこの機能を追加してもsscanfの機能を制限することにはなりません。
この機能は、nscanf.cのEOS_MATCHER_CHARの定義をコメントアウトすれば無効にできます。
