# プロジェクト憲章
## 前提条件
・VS2013以降の使用をすること
・C++11のコンパイルが可能な環境であること
・DirectX9(c)が動作する環境であること
・Utilityに対して適応しても良い

### Class
・コンストラクタ・デストラクタ・オペレータはC++11準拠,基本的にdefault指定で記述する(記述忘れ防止)
・変数の初期化はデフォルト値を持たせる(フィールド初期化or初期化リスト)
・テンプレート関数は.inlの中で定義する
・メンバ変数の宣言順は基本的にサイズ降順
・ポリシー、関数オブジェクト、ローカルクラス以外は.hと.cppを分離する

###例外
・プログラムを停止させなければならない事態に使用
・Exception.hに定義されている___THROW_EXCEPTION_POINTを使用する。
・main.cpp以外に記述するキャッチは必ずリレーする

###コメント
・関数(プロパティを除く)・クラス : DoxyGen(XML)準拠
・変数 ：パブリック・グローバルには記述
・存在しない場合は省略しても良い
・コメントスペース :
			1. file.
            2. include.
            3. define.
            4. ctor.dtor.(すべてデフォルトの場合は省略可)
            5. default.
            6. operator.
            7. fanction.
            8. property.
            9. val.
            10. EOF

###命名規約
・クラス：Cはつけず、アッパーキャメル
`Class FooClass;`

.インターフェース : Iをつけアッパーキャメル
`Class IFoo;`

・構造体：アッパーキャメル
`struct FooStruct;`

・引数：_　+　ローワーキャメル
`Foo(Foo _fooParam);`

・関数:アッパーキャメル
`FooFunction();`

・テンプレート型：アッパーキャメル
`template <class Type>`

 ・マクロ: \_\_\_ +　全大文字	スネーク(プロパティは除く)
`___FOO_MACRO(_param)`

・メンバー変数：m_ + セマンティクス + アッパーキャメル	
    ```int m_FooVal;
    int m_pFooVal;
    int m_hFooVal;```

・グローバル変数:g_ + セマンティクス + アッパーキャメル
    ```int g_FooVal;
    int g_pFooVal;
    int g_hFooVal;```

・ローカル変数：セマンティクス + ローワーキャメル
    ```int fooVal
    int pFooVal;
	int hFooVal;```
    
### 定数  
・基本的にPlanet9直下の名前空間ごとにConstantを定義する。  
・例外に使用する文字列は定数として扱わなくて良い。  

