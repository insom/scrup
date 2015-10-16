@interface HTTPPOSTOperation : NSOperation {
	NSString *__strong path;
	NSURL *__strong url;
	NSMutableURLRequest *request;
	NSHTTPURLResponse *__strong response;
	NSData *__strong responseData;
	id __strong delegate;
	//NSTimeInterval connectionRetryInterval;
	ASLLogger *__strong log;
}
@property(strong) NSString *path;
@property(strong) NSURL *url;
@property NSMutableURLRequest *request;
@property(strong) NSHTTPURLResponse *response;
@property(strong) NSData *responseData;
@property(strong) id delegate;
@property(strong) ASLLogger *log;
-(id)initWithPath:(NSString *)path URL:(NSURL *)url delegate:(id)delegate;
-(void)sendRequestAllowingRetries:(int)nretries;
@end

@protocol HTTPPOSTOperationDelegate
-(BOOL)preprocessFileBeforeSending:(HTTPPOSTOperation *)op;
-(void)httpPostOperationWillBegin:(HTTPPOSTOperation *)op;
-(void)httpPostOperationDidSucceed:(HTTPPOSTOperation *)op;
-(void)httpPostOperationDidFail:(HTTPPOSTOperation *)op withError:(NSError *)error;
@end
