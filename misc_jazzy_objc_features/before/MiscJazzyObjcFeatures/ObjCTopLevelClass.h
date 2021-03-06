//
//  ObjCTopLevelClass.h
//  MiscJazzyObjCFeatures
//
//  Created by Esad Hajdarevic on 11/02/16.
//  Copyright (c) 2016 PSPDFKit GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "SomeEnum.h"

@class Manager;

/// A dummy top level Objective-C class. Doesn't do much.
@interface ObjCTopLevelClass : NSObject
/**
 Always returns `SomeEnumFoo`
 
 @param param An important parameter
 @return `SomeEnumFoo` *even if* `-[NSObject load]` fails
 */
- (SomeEnum)methodReturningEnum:(NSString*)param;
@end

@interface ObjCTopLevelClass (SomeCategory)
/// Extends ObjCTopLevelClass in mysterious ways
- (void)categoryMethod:(NSString*)argument;
@end

@interface ObjCTopLevelClass (MarkedCategory)
#pragma mark Some marker
/// Extends ObjCTopLevelClass in even more mysterious ways
- (void)markedCategoryMethod:(NSString*)argument;
@end

/**
 A mid-level class. Does a little more than its superclass via
 `-prepareManager`.
 */
@interface ObjCMidLevelClass : ObjCTopLevelClass
/// Prepare a mid-level manager.
- (Manager *)prepareManager;
/// Unprepare a manager.  No longer supported.
- unprepare:(Manager *)manager  __attribute__((unavailable));
/// Create a manager.
- (Manager *)create __attribute__((deprecated("Use `-prepareManager`.")));
@end

/** A low-level class. */
__deprecated_msg("Deprecated: use `ObjCMidLevelClass`.")
@interface ObjCLowLevelClass: ObjCMidLevelClass
- (void)action;
@end

/// Some additions on `NSValue`.
@interface NSValue (SomeAdditions)

/// Creates and returns a value object containing the enumeration value.
+ (instancetype)valueWithSomeEnum:(SomeEnum)someEnum;

/// Returns the enumeration value contained in the receiver.
@property (nonatomic, readonly) SomeEnum someEnumValue;

@end

/// Some more additions on `NSValue`.
@interface NSValue (SomeMoreAdditions)

/// Creates and returns a value object containing the enumeration value.
+ (instancetype)valueWithSomeMoreEnum:(SomeEnum)someEnum;

/// Returns the enumeration value contained in the receiver.
@property (nonatomic, readonly) SomeEnum someMoreEnumValue;

@end
