#import <AppKit/NSNibDeclarations.h>
#import "NSPreferences.h"

@class WebView;
@class NSPopUpButton;
@class NSTextView;
@class JVFontPreviewField;
@class NSTextField;
@class NSStepper;
@class NSSet;
@class NSDrawer;
@class NSTableView;

@interface JVAppearancePreferences : NSPreferencesModule {
	IBOutlet WebView *preview;
	IBOutlet NSPopUpButton *styles;
	IBOutlet NSPopUpButton *emoticons;
	IBOutlet JVFontPreviewField *standardFont;
	IBOutlet NSTextField *minimumFontSize;
	IBOutlet NSStepper *minimumFontSizeStepper;
	IBOutlet NSTextField *baseFontSize;
	IBOutlet NSStepper *baseFontSizeStepper;
	IBOutlet NSDrawer *optionsDrawer;
	IBOutlet NSTableView *optionsTable;
	IBOutlet NSPanel *newVariantPanel;
	IBOutlet NSTextField *newVariantName;
	BOOL _variantLocked;
	BOOL _alertDisplayed;
	NSSet *_styleBundles;
	NSSet *_emoticonBundles;
	NSMutableArray *_styleOptions;
	NSString *_userStyle;
}
- (void) changePreferences:(id) sender;

- (IBAction) changeBaseFontSize:(id) sender;
- (IBAction) changeMinimumFontSize:(id) sender;

- (IBAction) changeDefaultChatStyle:(id) sender;

- (IBAction) noGraphicEmoticons:(id) sender;
- (IBAction) changeDefaultEmoticons:(id) sender;

- (IBAction) showOptions:(id) sender;

- (void) updateChatStylesMenu;
- (void) updateEmoticonsMenu;
- (void) updatePreview;

- (void) parseStyleOptions;
- (NSString *) valueOfProperty:(NSString *) property forSelector:(NSString *) selector inStyle:(NSString *) style;
- (void) setStyleProperty:(NSString *) property forSelector:(NSString *) selector toValue:(NSString *) value;
- (void) setUserStyle:(NSString *) style;
- (void) saveStyleOptions;

- (void) showNewVariantSheet;
- (IBAction) closeNewVariantSheet:(id) sender;
- (IBAction) createNewVariant:(id) sender;
@end
