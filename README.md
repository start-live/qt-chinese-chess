# qt-chinese-chess
qt实现中国象棋
# 棋子行走规则
所有棋子都无法移动到的地方：
1，新位置不在棋盘范围之内
2，新位置是原来的位置
3，新位置有己方棋子

车不能移动到的地方：
1，新位置与自己位置的行和列都不相同
2，新位置与自己位置中间有棋子

马不能移动到的地方：
1，新位置与自己位置形成的马脚有棋子
2，新位置与自己位置不能形成日子

象不能移动到的地方：
1，新位置与自己位置形成的象眼有棋子
2，新位置与自己位置不能形成田子

士不能移动到的地方：
1，新位置不在九宫格之内
2，新位置与自己位置不能形成口字

将不能移动到的地方：
1，新位置不在九宫格之内
2，新位置与自己位置不是相隔一行或者一列

炮不能移动到的地方：
1，新位置与自己位置行和列都不相同
2，新位置与自己位置中间有两颗以上的棋子
3，新位置与自己位置中间有一颗棋子，但新位置没有地方棋子
