//
//  EFSelectCityVC.m
//  Dentist
//
//  Created by HqLee on 16/7/13.
//  Copyright © 2016年 KingYon LLC. All rights reserved.
//

#import "EFSelectCityVC.h"
#import "EFMallModel.h"

static NSString *cellID = @"city";

@interface EFSelectCityVC()<UITableViewDelegate,UITableViewDataSource>
@property (nonatomic, copy) SelectHandler selectHandler;
//cityFileName 路径
@property (nonatomic, copy) NSString *regionFileName;
//根数组
@property (nonatomic, strong) NSArray *arrayRoot;
@property (nonatomic, strong) NSArray *cityArray;
@end
@implementation EFSelectCityVC
#pragma mark --- life cycle
- (instancetype)initWithSelectHandler:(SelectHandler)selectHandler{
    if (self = [super init]) {
        self.selectHandler = [selectHandler copy];
    }
    return self;
}

- (void)viewDidLoad{
//    self.cityArray = [NSArray yy_modelArrayWithClass:[CategoryModel class] json:self.arrayRoot];
    [self setupNavi];
    [self setupView];
}

- (void)setupNavi{
    self.title = @"选择城市";
    UIButton *backBtn = [UIButton buttonWithType:UIButtonTypeCustom];
    [backBtn setTitle:@"返回" forState:UIControlStateNormal];
    [backBtn sizeToFit];
    [backBtn setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
    [backBtn addTarget:self action:@selector(backBtnClick) forControlEvents:UIControlEventTouchUpInside];
    UIBarButtonItem *leftItem = [[UIBarButtonItem alloc] initWithCustomView:backBtn];
    self.navigationItem.leftBarButtonItem = leftItem;
}

- (void)setupView{
    UITableView *tableView = [[UITableView alloc] initWithFrame:CGRectZero style:UITableViewStylePlain];
    tableView.tableFooterView = [[UIView alloc] initWithFrame:CGRectZero];
    tableView.delegate = self;
    tableView.dataSource = self;
    tableView.rowHeight = 44;
    [tableView registerClass:[UITableViewCell class] forCellReuseIdentifier:cellID];
    [self.view addSubview:tableView];
    tableView.sd_layout.spaceToSuperView(UIEdgeInsetsZero);
}

#pragma mark - --- getters 属性 ---
- (NSString *)regionFileName{
    if (_regionFileName == nil) {
        _regionFileName = [[NSBundle mainBundle] pathForResource:@"city.plist" ofType:nil];
    }
    return _regionFileName;
}

- (NSArray *)arrayRoot
{
    if (_arrayRoot == nil) {
        _arrayRoot = [[NSArray alloc]initWithContentsOfFile:self.regionFileName];
    }
    return _arrayRoot;
}

#pragma mark ---<UITableViewDelegate,UITableViewDataSource>
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section{
    return self.arrayRoot.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath{
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:cellID];
    NSDictionary *dict = self.arrayRoot[indexPath.row];
    cell.textLabel.text = dict[@"name"];
    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath{
    NSDictionary *dict = self.arrayRoot[indexPath.row];
    !self.selectHandler ? :self.selectHandler(dict[@"name"],dict[@"objectId"]);
    [self dismissViewControllerAnimated:YES completion:nil];
}

- (void)backBtnClick{
    [self dismissViewControllerAnimated:YES completion:nil];
}
@end
