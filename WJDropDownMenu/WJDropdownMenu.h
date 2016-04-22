
// 如有任何bug、不足、功能不全之处请在github不上找我，我会第一时间回复并修正
// github:https://github.com/wjTime/WJDropDownMenu.git 实时更新中...

#import <UIKit/UIKit.h>


typedef enum:NSInteger{
    menuArrowStyleSolid  = 0,
    menuArrowStyleHollow = 1,
}menuArrowStyle;

@protocol WJMenuDelegate <NSObject>


@optional
#pragma mark -- 数据返回的代理方法

/** 代理方法返回 菜单标题index:MenuTitleIndex  一级菜单index:firstIndex  二级菜单index:secondIndex */
- (void)menuCellDidSelected:(NSInteger)MenuTitleIndex firstIndex:(NSInteger)firstIndex andSecondIndex:(NSInteger)secondIndex;

/** 代理方法返回 菜单标题:MenuTitle  一级菜单内容:firstContent  二级菜单内容:secondContent */
- (void)menuCellDidSelected:(NSString *)MenuTitle firstContent:(NSString *)firstContent andSecondContent:(NSString *)secondContent;

/** 代理方法返回 菜单标题index:MenuTitleIndex  一级菜单index:firstIndex  二级菜单index:secondIndex  三级菜单index:thirdIndex */
- (void)menuCellDidSelected:(NSInteger)MenuTitleIndex firstIndex:(NSInteger)firstIndex secondIndex:(NSInteger)secondIndex thirdIndex:(NSInteger)thirdIndex;

/** 代理方法返回 菜单标题:MenuTitle  一级菜单内容:firstContent 二级菜单内容:secondContent  三级菜单内容:thirdContent */
- (void)menuCellDidSelected:(NSString *)MenuTitle firstContent:(NSString *)firstContent secondContent:(NSString *)secondContent thirdContent:(NSString *)thirdContent;


#pragma mark -- net一级一级点击网络获取数据的代理方法（在此代理方法中调用 netLoad 开头的方法 导入一级一级网络请求返回的数据）

/** net代理方法返回 菜单标题index:MenuTitleIndex 菜单标题:MenuTitle */
- (void)netMenuClickMenuIndex:(NSInteger)menuIndex menuTitle:(NSString *)menuTitle;

/** net代理方法返回 菜单标题index:MenuTitleIndex 菜单标题:MenuTitle  一级菜单内容:firstContent  一级菜单内容:firstContent */
- (void)netMenuClickMenuIndex:(NSInteger)menuIndex menuTitle:(NSString *)menuTitle FirstIndex:(NSInteger)FirstIndex firstContent:(NSString *)firstContent;

@end



@interface WJDropdownMenu : UIView<UITableViewDataSource,UITableViewDelegate,UIGestureRecognizerDelegate>


#pragma mark -- 属性设置
/** 关闭遮盖功能 */
@property (nonatomic,strong)UIColor *CarverViewColor;

/** 遮盖的动画时间 */
@property (nonatomic,assign)CGFloat caverAnimationTime;

/** 菜单title的字体大小 */
@property (nonatomic,assign)CGFloat menuTitleFont;

/** 下拉菜单的的字体大小 */
@property (nonatomic,assign)CGFloat tableTitleFont;

/** 下拉菜单的的字体大小 */
@property (nonatomic,assign)CGFloat menuHeight;

/** 下拉菜单cell的高度 */
@property (nonatomic,assign)CGFloat cellHeight;

/** 旋转箭头的样式 */
@property (nonatomic,assign)menuArrowStyle menuArrowStyle;

/** 下拉的Tableview最大高度(超出高度可以滑动显示) */
@property (nonatomic,assign)CGFloat tableViewMaxHeight;

/** 设置代理 */
@property (nonatomic,assign) id<WJMenuDelegate>delegate;



#pragma mark -- 一次性创建所有菜单数据
/** 创建一组下拉菜单 */
- (void)createOneMenuTitleArray:(NSArray *)menuTitleArray FirstArray:(NSArray *)FirstArray;

/** 创建两组下拉菜单 */
- (void)createTwoMenuTitleArray:(NSArray *)menuTitleArray FirstArr:(NSArray *)firstArr SecondArr:(NSArray *)secondArr;

/** 创建三组下拉菜单 */
- (void)createThreeMenuTitleArray:(NSArray *)menuTitleArray FirstArr:(NSArray *)firstArr SecondArr:(NSArray *)secondArr threeArr:(NSArray *)threeArr;

/** 创建四组下拉菜单 */
- (void)createFourMenuTitleArray:(NSArray *)menuTitleArray FirstArr:(NSArray *)firstArr SecondArr:(NSArray *)secondArr threeArr:(NSArray *)threeArr fourArr:(NSArray *)fourArr;

/** 收缩菜单 */
- (void)drawBackMenu;


#pragma mark -- net一级一级点击网络获取数据创建

/** net创建下拉菜单 */
- (void)netCreateMenuTitleArray:(NSArray *)menuTitleArray;

/** net导入一级菜单数据 */
- (void)netLoadFirstArray:(NSArray *)firstArray;

/** net导入二级菜单数据 */
- (void)netLoadSecondArray:(NSArray *)SecondArray;


@end
