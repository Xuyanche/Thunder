# Thunder!!!!

## 需求分析

### 开始界面
- 开始
- 积分榜
- 退出

### 游戏
- boss战  
旋转弹幕  
血量  

- 飞机：  
攻击模式  
通过键盘操作飞机移动  
一击致命

- 背景：一张图

### 结束界面
- 祝贺/你死了


### 实现

#### 类
- 自己的飞机
- 属性：
   - 位置
   - 攻击模式
   - 生命
- 方法：
   - 被击判定
   - 移动
   - 申请发射子弹（不同攻击模式）

- boss
- 属性：
  - 生命
  - 位置

- 方法：
  - 申请发射子弹
  - 移动
  - 被击判定
  - 死亡


- 子弹manager
  - 子弹：
    - 位置
    - 伤害
    - 敌我
    - 消失（击中/出去）
    - 移动路径

#### 界面

