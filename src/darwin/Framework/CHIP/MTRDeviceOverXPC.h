/**
 *
 *    Copyright (c) 2022 Project CHIP Authors
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

#import "MTRBaseDevice.h"
#import "MTRCluster.h" // For MTRSubscriptionEstablishedHandler
#import "MTRDeviceControllerXPCConnection.h"

NS_ASSUME_NONNULL_BEGIN

@interface MTRDeviceOverXPC : MTRBaseDevice

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;
- (void)subscribeWithQueue:(dispatch_queue_t)queue
                minInterval:(NSNumber *)minInterval
                maxInterval:(NSNumber *)maxInterval
              reportHandler:(void (^)(NSArray * _Nullable value, NSError * _Nullable error))reportHandler
    subscriptionEstablished:(MTRSubscriptionEstablishedHandler _Nullable)subscriptionEstablishedHandler NS_UNAVAILABLE;

- (instancetype)initWithController:(id<NSCopying>)controller
                          deviceID:(NSNumber *)deviceID
                     xpcConnection:(MTRDeviceControllerXPCConnection *)xpcConnection;

@end

NS_ASSUME_NONNULL_END
