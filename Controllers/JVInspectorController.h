@protocol JVInspection;

@protocol JVInspector <NSObject>
- (NSView *) view;
- (NSSize) minSize;
- (NSString *) title;
- (NSString *) type;
@end

@interface NSObject (JVInspectorOptional)
- (void) willLoad;
- (void) didLoad;

- (BOOL) shouldUnload;
- (void) didUnload;
@end

@protocol JVInspection <NSObject>
- (id <JVInspector>) inspector;
@end

@interface NSObject (JVInspectionOptional)
- (void) willBeInspected;
@end

@protocol JVInspectionDelegator <NSObject>
- (id <JVInspection>) objectToInspect;
- (IBAction) getInfo:(id) sender;
@end

@interface JVInspectorController : NSWindowController <NSWindowDelegate> {
	BOOL _locked;
	id <JVInspection> _object;
	id <JVInspector> _inspector;
	BOOL _inspectorLoaded;
}
+ (JVInspectorController *) sharedInspector;
+ (IBAction) showInspector:(id) sender;
+ (JVInspectorController *) inspectorOfObject:(id <JVInspection>) object NS_RETURNS_NOT_RETAINED;

- (id) initWithObject:(id <JVInspection>) object lockedOn:(BOOL) locked;

- (IBAction) show:(id) sender;
- (BOOL) locked;

- (void) inspectObject:(id <JVInspection>) object;

- (id <JVInspection>) inspectedObject;
- (id <JVInspector>) inspector;
@end
