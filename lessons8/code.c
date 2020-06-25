//打开和关闭与数字连接的发光二极管（LED）

//pin，不使用delay（）函数。这意味着其他代码

//可同时运行，不受LED代码干扰。



//电路：

//*使用车载LED。

//*注意：大多数Arduinos都有一个可以控制的车载LED。在UNO上，MEGA和ZERO

//它连接到数字管脚13，MKR1000的管脚6。LED内置设置为

//正确的LED管脚，与所使用的电路板无关。





//常数不会改变。用于设置pin码
const int ledPin =  LED_BUILTIN;// LED的 pin值

//变量将更改
int ledState = LOW;             // 用于设置LED的LED状态

//一般来说，对于保存时间的变量，应该使用“unsigned long”

//值很快就会变得太大，无法存储int
unsigned long previousMillis = 0;        // 将存储上次更新LED的时间

// 常数不变 :
const long interval = 1000;           // 闪烁间隔 毫秒

void setup() {
  // 将数字管脚设置为输出
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // 检查LED是否闪烁；也就是说，如果

//当前时间与上次闪烁时间之间的差异

//LED大于您希望的间隔

//使LED闪烁
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // 保存上次闪烁LED的时间
    previousMillis = currentMillis;

    //如果LED熄灭，则将其打开，反之亦然
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

    // 用变量的ledState设置LED
    digitalWrite(ledPin, ledState);
  }
}