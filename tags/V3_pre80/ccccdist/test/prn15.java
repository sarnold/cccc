// prn15.java

// This test case looks at the effect of large
// numbers of degenerate case labels.

// It is based on a sample submitted by Jordan Zimmerman
// which was apparently causing CCCC to hang.

public class Prn15
{
	public Image get_image(int image_code)
	{
		switch ( image_code )
		{
			case cc_def.IMAGE_BUTTON_SUBMIT:
			case cc_def.IMAGE_BUTTON_SIGN_IN:
			case cc_def.IMAGE_BUTTON_SEARCH:
			case cc_def.IMAGE_BUTTON_SEARCH_CATEGORIES:
			case cc_def.IMAGE_BUTTON_PREVIOUS:
			case cc_def.IMAGE_BUTTON_PREVIOUS_GRAY:
			case cc_def.IMAGE_BUTTON_NEXT:
			case cc_def.IMAGE_BUTTON_NEXT_GRAY:
			case cc_def.IMAGE_BUTTON_GO_NAV:
            case cc_def.IMAGE_BUTTON_SIGN_IN_SECURE:
			case cc_def.IMAGE_BUTTON_GO_CONTENT:
			case cc_def.IMAGE_BUTTON_OK:
			case cc_def.IMAGE_CCMOS_BUTTON_OK:
			case cc_def.IMAGE_CCMOS_BUTTON_CANCEL:
			case cc_def.IMAGE_BUTTON_CANCEL:
			case cc_def.IMAGE_BUTTON_ADD_TO_CART:
			case cc_def.IMAGE_BUTTON_SAVE_TO_REGISTRY:
			case cc_def.IMAGE_BUTTON_ADD_CREDIT_CARD:
			case cc_def.IMAGE_BUTTON_ADD_REMINDER:
			case cc_def.IMAGE_BUTTON_UPDATE_REMINDER:
			case cc_def.IMAGE_BUTTON_CANCEL_REMINDER:
			case cc_def.IMAGE_BUTTON_SUGGEST_GIFTS:
			case cc_def.IMAGE_BUTTON_CONTINUE_SHOPPING_SMALL:
			case cc_def.IMAGE_BUTTON_CREATE_REGISTRY:
			case cc_def.IMAGE_BUTTON_UPDATE_REGISTRY:
			case cc_def.IMAGE_BUTTON_DELETE_REGISTRY:
			case cc_def.IMAGE_BUTTON_CONTINUE_SECURE:
			case cc_def.IMAGE_BUTTON_SEND_EMAIL:
			case cc_def.IMAGE_BUTTON_REDEEM_COUPON:
			case cc_def.IMAGE_BUTTON_REDEEM_CERTIFICATE:
			case cc_def.IMAGE_BUTTON_SHOW_CREDIT_BALANCE:
			case cc_def.IMAGE_BUTTON_HELP:
			case cc_def.IMAGE_BUTTON_CONTINUE:
			case cc_def.IMAGE_BUTTON_BACK:
			case cc_def.IMAGE_BUTTON_SHIP_IT:
			case cc_def.IMAGE_BUTTON_SKIP_TOUR:
			case cc_def.IMAGE_BUTTON_ECARD_PERSONALIZE:
			case cc_def.IMAGE_BUTTON_ECARD_VIEW:
			case cc_def.IMAGE_BUTTON_ECARD_SEND:
			case cc_def.IMAGE_BUTTON_ENTER:
            case cc_def.IMAGE_BUTTON_ADD_ADDRESS:
			{
				try
				{
					return get_dynamic_button(image_code);
				}
				catch ( ServletException the_exception )
				{
					the_exception.printStackTrace();
					return null;
				}
			}
			
            default:
            	return null;
		}

		return null;
	}

}

