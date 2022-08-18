/*
 Copyright (c) 2014-present, salesforce.com, inc. All rights reserved.
 
 Redistribution and use of this software in source and binary forms, with or without modification,
 are permitted provided that the following conditions are met:
 * Redistributions of source code must retain the above copyright notice, this list of conditions
 and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright notice, this list of
 conditions and the following disclaimer in the documentation and/or other materials provided
 with the distribution.
 * Neither the name of salesforce.com, inc. nor the names of its contributors may be used to
 endorse or promote products derived from this software without specific prior written
 permission of salesforce.com, inc.
 
 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR
 IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
 FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY
 WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#import <Foundation/Foundation.h>
#import "SFEncryptionKey.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Singleton class to manage operations on the keystore.
 */
@interface SFKeyStoreManager : NSObject

/**
 @return Shared instance of the keystore manager.
 */
+ (instancetype)sharedInstance;

/**
 Retrieves a key with the given label from the keystore or `nil`, depending on the `autoCreate` value.
 @param keyLabel Label associated with the stored key.
 @param create Indicates whether a new key should be created if one does not exist.
 @returns Encryption key or `nil`, depending on the `autoCreate` value.
 */
- (SFEncryptionKey *)retrieveKeyWithLabel:(NSString *)keyLabel autoCreate:(BOOL)create;

/**
 Stores a key with the given label in the keystore encrypted by the store's key.
 @param key Encryption key to be stored.
 @param keyLabel Label associated with the key.
 */
- (void)storeKey:(SFEncryptionKey *)key withLabel:(NSString *)keyLabel;

/**
 Removes the key with the given label from the keystore.
 @param keyLabel Label associated with the key to remove.
 */
- (void)removeKeyWithLabel:(NSString *)keyLabel;

/**
 Determines whether a key with the given label exists.
 @param keyLabel Label associated with the key to query.
 @returns YES if the key exists in the keystore; NO otherwise.
 */
- (BOOL)keyWithLabelExists:(NSString *)keyLabel;

/**
 Determines whether a key with the given label exists.
 @param keyLabel Label associated with the key to query.
 @returns YES if the key exists in the keystore; NO otherwise.
 */
- (BOOL)keyExists:(NSString *)keyLabel keychain:(NSString *)keychain;

/**
Stores data on iOS keychain with a provided keychain ID.
@param data The data to store on keychain.
@param key the key for the data.
@param keychain the id for the keychain.
 */
- (OSStatus)storeData:(NSData *)data forKey:(NSString *)key keychainID:(NSString *)keychain;

/**
Extract data from keychain with corresponding keychain ID.
@param key The key for the corresponding value.
@param keychain The ID for the keychain.
 */
- (nullable NSData *) dataForKey:(NSString *)key keychainID:(NSString *)keychain;

/// Removes the keychainItem from the keychain
/// @param keychain id used to determine which keychain item to remove
/// @returns returns true if successfully able to remove keychain item else false
- (BOOL) removeKeyChainWithID:(NSString *)keychain;

@end

NS_ASSUME_NONNULL_END
