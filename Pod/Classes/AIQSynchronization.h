#ifndef AIQCoreLib_AIQSynchronization_h
#define AIQCoreLib_AIQSynchronization_h

#import <Foundation/Foundation.h>

/*!
 @header AIQSynchronization.h
 @author Marcin Lukow
 @copyright 2014 Appear Networks Systems AB
 @updated 2014-08-11
 @brief AIQSynchronization module can be used to synchronize business documents to and from the backend.
 @version 1.3.0
 */

@class AIQSession;
@class AIQSynchronization;

typedef NS_ENUM(NSUInteger, AIQSynchronizationResult) {
    AIQSynchronizationResultNewData,
    AIQSynchronizationResultNoData,
    AIQSynchronizationResultFailed
};

/** Timeout interval for synchronizing documents.
 
 This timeout interval is used for making document synchronization requests to the backend under weak
 connectivity circumstances. This is the default value which is used when the AIQSynchronization module was initialized
 without specifying the custom timeout interval.
 
 @since 1.0.0
 */
EXTERN_API(NSTimeInterval) const AIQSynchronizationDocumentTimeout;

/** Timeout interval for synchronizing attachments.
 
 This timeout interval is used for making attachment synchronization requests to the backend under weak
 connectivity circumstances. This is the default value which is used when the AIQSynchronization module was initialized
 without specifying the custom timeout interval.
 
 @since 1.0.0
 */
EXTERN_API(NSTimeInterval) const AIQSynchronizationAttachmentTimeout;

/** Error code for blocked accounts.
 
 This error code is used for NSErrors raised when specified access token is no longer valid.
 
 @since 1.0.0
 @see synchronization:didFailWithError:
 */
EXTERN_API(NSInteger) const AIQSynchronizationGoneError;

EXTERN_API(NSString *) const AIQSolutionUserInfoKey;
EXTERN_API(NSString *) const AIQDocumentIdUserInfoKey;
EXTERN_API(NSString *) const AIQDocumentTypeUserInfoKey;

EXTERN_API(NSString *) const AIQAttachmentNameUserInfoKey;

/** User info key for attachment download progress.
 
 This key is used to store the progress of the attachment being downloaded.
 
 @since 1.0.0
 */
EXTERN_API(NSString *) const AIQAttachmentProgressUserInfoKey;

/** User info key for document and attachment rejection reason.
 
 This key is used to store the rejection reason for synchronized documents and attachments. It can be
 used to retrieve the reason from the User Info map provided by the NSNotification.
 
 @since 1.0.0
 @see DocumentRejectedEventKey
 @see AIQRejectionReason
 */
EXTERN_API(NSString *) const AIQRejectionReasonUserInfoKey;

/** User info key for document and attachment synchronization error code.
 
 This key is used to store the error code for documents and attachments that failed to synchronize. It can be
 used to retrieve the reason from the User Info map provided by the NSNotification.
 
 @since 1.4.0
 @see AIQDocumentErrorEventKey
 @see AQAttachmentErrorEventKey
 */
EXTERN_API(NSString *) const AIQErrorCodeUserInfoKey;

EXTERN_API(NSString *) const AIQSynchronizationStatusUserInfoKey;

/** Document created event name.
 
 This is the name of the event generated by NSNotificationCenter when a business document has been
 stored in local data store.
 
 @since 1.0.0
 */
EXTERN_API(NSString *) const AIQDidCreateDocumentNotification;

/** Document updated event name.
 
 This is the name of the event generated by NSNotificationCenter when a business document has been
 updated in local data store.
 
 @since 1.0.0
 */
EXTERN_API(NSString *) const AIQDidUpdateDocumentNotification;

/** Document deleted event name.
 
 This is the name of the event generated by NSNotificationCenter when a business document has been removed
 from local data store.
 
 @since 1.0.0
 */
EXTERN_API(NSString *) const AIQDidDeleteDocumentNotification;

/** Document synchronized event name.
 
 This is the name of the event generated by NSNotificationCenter when a business document has been
 accepted by the backend after uploading local changes.
 
 @since 1.0.0
 */
EXTERN_API(NSString *) const AIQDidSynchronizeDocumentNotification;

/** Document rejected event name.
 
 This is the name of the event generated by NSNotificationCenter when a business document has been
 rejected by the backend after uploading local changes.
 
 @since 1.0.0
 @see AIQSynchronizationRejectionReasonKey
 */
EXTERN_API(NSString *) const AIQDidRejectDocumentNotification;

/** Document synchronization error event name.
 
 This is the name of the event generated by NSNotificationCenter when a business document has failed to synchronize
 with the AIQ Server due to an error.
 
 @since 1.0.0
 @see AIQRejectionReasonUserInfoKey
 @see AIQErrorCodeUserInfoKey
 */
EXTERN_API(NSString *) const AIQDocumentErrorNotification;

EXTERN_API(NSString *) const AIQDidCreateAttachmentNotification;
EXTERN_API(NSString *) const AIQDidUpdateAttachmentNotification;
EXTERN_API(NSString *) const AIQDidDeleteAttachmentNotification;

/** Attachment will download event name.
 
 This is the name of the event generated by NSNotificationCenter when an attachment is about to be downloaded
 into local data store.
 
 @since 1.0.0
 */
EXTERN_API(NSString *) const AIQWillDownloadAttachmentNotification;

/** Attachment available event name.
 
 This is the name of the event generated by NSNotificationCenter when an attachment has been downloaded
 and is now available.
 
 @since 1.0.0
 */
EXTERN_API(NSString *) const AIQAttachmentDidBecomeAvailableNotification;

/** Attachment unavailable event name.
 
 This is the name of the event generated by NSNotificationCenter when an attachment has temporarily failed to
 download and is unavailable locally.
 
 @since 1.0.0
 */
EXTERN_API(NSString *) const AIQAttachmentDidBecomeUnavailableNotification;

/** Attachment failed event name.
 
 This is the name of the event generated by NSNotificationCenter when an attachment has permanently failed to
 download and is unavailable locally.
 
 @since 1.0.0
 */
EXTERN_API(NSString *) const AIQAttachmentDidFailNotification;

/** Attachment download progress event name.
 
 This is the name of the event generated by NSNotificationCenter when an attachment is being downloaded.
 
 @since 1.0.0
 */
EXTERN_API(NSString *) const AIQAttachmentDidProgressNotification;

/** Attachment synchronized event name.
 
 This is the name of the event generated by NSNotificationCenter when an attachment has been accepted by
 the backend after uploading local changes.
 
 @since 1.0.0
 */
EXTERN_API(NSString *) const AIQDidSynchronizeAttachmentNotification;

/** Attachment rejected event name.
 
 This is the name of the event generated by NSNotificationCenter when an attachment has been rejected by
 the backend after uploading local changes.
 
 @since 1.0.0
 */
EXTERN_API(NSString *) const AIQDidRejectAttachmentNotification;

/** Attachment synchronization error event name.
 
 This is the name of the event generated by NSNotificationCenter when an attachment has failed to synchronize
 with the AIQ Server due to an error.
 
 @since 1.0.0
 @see AIQSynchronizationRejectionReasonKey
 @see AIQSynchronizationErrorCodeKey
 */
EXTERN_API(NSString *) const AIQAttachmentErrorNotification;

/** Delegate for the AIQSynchronization module.
 
 This delegate can be used to receive notifications about the outcome of the synchronization process.
 
 @since 1.0.0
 */
@protocol AIQSynchronizationDelegate <NSObject>

/** Notifies that synchronization has finished.
 
 This method will be called when the synchronization of business documents has been successfully completed.
 Note that attachments are decoupled from business documents which means that they can be processed even
 after this method is called.
 
 @param synchronization AIQSynchronization module instance that has finished the synchronization. Will not
 be nil.
 
 @since 1.0.4
 @see synchronize:
 */
- (void)didSynchronize:(AIQSynchronization *)synchronization;

/** Notifies that synchronization has failed.
 
 This method will be called when the synchronization of business documents has failed.
 
 @param synchronization AIQSynchronization module instance that has failed to synchronize. Will not be nil.
 @param error Will store the cause of failure. Will not be nil.
 
 @since 1.0.4
 @see synchronize:
 */
- (void)synchronization:(AIQSynchronization *)synchronization didFailWithError:(NSError *)error;

@end

/** AIQSynchronization module.
 
 This module provides means to synchronize business documents to and from the backend.
 
 @since 1.0.0
 */
@interface AIQSynchronization : NSObject<NSURLConnectionDataDelegate>

/**---------------------------------------------------------------------------------------
 * @name Properties
 * ---------------------------------------------------------------------------------------
 */

/** AIQSynchronization delegate.
 
 This delegate, if specified, will be notified about the outcome of the synchronization process. Can be nil.
 
 @since 1.0.0
 */
@property (nonatomic, retain) id<AIQSynchronizationDelegate> delegate;

/** Request timeout for processing business documents.
 
 This timeout will be used to download or upload business documents.
 
 @since 1.0.4
 @see AIQSynchronizationDocumentTimeout
 */
@property (nonatomic, assign) NSTimeInterval documentTimeout;

/** Request timeout for processing attachments.
 
 This timeout will be used to download or upload attachments.
 
 @since 1.0.4
 @see AIQSynchronizationAttachmentTimeout
 */
@property (nonatomic, assign) NSTimeInterval attachmentTimeout;

/**---------------------------------------------------------------------------------------
 * @name Data synchronization
 * ---------------------------------------------------------------------------------------
 */

/** Requests synchronization.
 
 This method can be used to trigger asynchronous synchronization of business documents. Remote changes are pulled from
 the mobility platform first and then local changes are pushed. Any changes made to documents which were remotely updated
 are lost. Attachments belonging to these documents are decoupled from their owners which means that delegate will get
 notified before processing all attachments. It is impossible to perform two synchronizations in the same time.
 
 @param error If defined, will store an error in case of any failure. May be nil.
 @return YES if synchronization was possible, NO otherwise, in which case the error parameter will contain the reason of
 failure.
 
 @since 1.0.4
 */
- (BOOL)synchronize:(NSError **)error;

- (void)synchronizeWithCompletionHandler:(void (^)(AIQSynchronizationResult))handler;

/** Cancels ongoing synchronization process.
 
 This method can be used to cancel an ongoing synchronization. If the process is not running, this method will not do
 anything, but it will succeeed.
 
 @param error If defined, will store an error in case of any failure. May be nil.
 @return YES if cancellation was possible, NO otherwise, in which case the error parameter will contain the reason of
 failure.
 
 @since 1.0.4
 */
- (BOOL)cancel:(NSError **)error;

/** Tells whether the synchronization process is running.
 
 @return YES if the synchronization process is running, NO otherwise.
 
 @since 1.0.4
 */
- (BOOL)isRunning;

- (void)close;

@end

#endif /* AIQCoreLib_AIQSynchronization_h */
