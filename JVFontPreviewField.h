#import <AppKit/NSTextField.h>

@class NSFont;

@interface JVFontPreviewField : NSTextField {
	NSFont *_actualFont;
	BOOL _showPointSize;
}
- (void) selectFont:(id) sender;
- (IBAction) chooseFontWithFontPanel:(id) sender;
- (void) setShowPointSize:(BOOL) show;
@end

@interface NSObject (JVFontPreviewFieldDelegate)
- (BOOL) fontPreviewField:(JVFontPreviewField *) field shouldChangeToFont:(NSFont *) font;
- (void) fontPreviewField:(JVFontPreviewField *) field didChangeToFont:(NSFont *) font;
@end