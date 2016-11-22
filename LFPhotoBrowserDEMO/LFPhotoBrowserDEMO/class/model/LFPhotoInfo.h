//
//  PhotoInfo.h
//  PhotoBrowser
//
//  Created by LamTsanFeng on 2016/9/28.
//  Copyright © 2016年 GZMiracle. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "LFPhotoProtocol.h"
#import "LFVideoProtocol.h"

typedef NS_ENUM(NSInteger, PhotoType) {
    /** 默认 图片 */
    PhotoType_image,
    /** 视频 */
    PhotoType_video,
};


@interface LFPhotoInfo : NSObject <LFPhotoProtocol, LFVideoProtocol>

@property (nonatomic, readonly) PhotoType photoType;
/** 唯一识别的key*/
@property (nonatomic, copy, readonly) NSString *key;
/** 进度 */
@property (nonatomic, assign) float downloadProgress;
/** 下载失败记录，显示另外UI */
@property (nonatomic, assign) BOOL downloadFail;

/** 图片读取优先级  低->高 往下 */
/** 占位图片*/
@property (nonatomic, strong) UIImage *placeholderImage;


/** ************LFPhotoProtocol************ */

/** 缩略图URLString*/
@property (nonatomic, copy) NSString *thumbnailUrl;
/** 缩略图路径*/
@property (nonatomic, copy) NSString *thumbnailPath;
/** 缩略图图片*/
@property (nonatomic, strong) UIImage *thumbnailImage;

/** 原图URLString*/
@property (nonatomic, copy) NSString *originalImageUrl;
/** 图片本地路径*/
@property (nonatomic, copy) NSString *originalImagePath;
/** 本地图片、保存下载图片*/
@property (nonatomic, copy) UIImage *originalImage;

/** ************LFVideoProtocol************ */

/** 视频URLString*/
@property (nonatomic, copy) NSString *videoUrl;
/** 视频路径*/
@property (nonatomic, copy) NSString *videoPath;
/** 是否需要进度条 */
@property (nonatomic, assign) BOOL isNeedSlider;



+ (instancetype)photoInfoWithType:(PhotoType)type key:(NSString *)key;
@end
