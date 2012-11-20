<?php /* Smarty version Smarty-3.1.12, created on 2012-11-20 16:50:05
         compiled from "./templates/index.tpl.html" */ ?>
<?php /*%%SmartyHeaderCode:55137751150ab8e39259343-71312677%%*/if(!defined('SMARTY_DIR')) exit('no direct access allowed');
$_valid = $_smarty_tpl->decodeProperties(array (
  'file_dependency' => 
  array (
    '01ecfae32e301db98e9a68ae3b8db3604ec329d7' => 
    array (
      0 => './templates/index.tpl.html',
      1 => 1353422993,
      2 => 'file',
    ),
  ),
  'nocache_hash' => '55137751150ab8e39259343-71312677',
  'function' => 
  array (
  ),
  'version' => 'Smarty-3.1.12',
  'unifunc' => 'content_50ab8e392b86d1_08905127',
  'variables' => 
  array (
    'user_logined' => 0,
  ),
  'has_nocache_code' => false,
),false); /*/%%SmartyHeaderCode%%*/?>
<?php if ($_valid && !is_callable('content_50ab8e392b86d1_08905127')) {function content_50ab8e392b86d1_08905127($_smarty_tpl) {?><!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<?php echo $_smarty_tpl->getSubTemplate ("head.tpl.html", $_smarty_tpl->cache_id, $_smarty_tpl->compile_id, null, null, array(), 0);?>

<body>
    <center>
        <table width="100%" border="0" cellspacing="0" cellpadding="0">
            <tr>
                <td align="center" style="padding-left:20px;padding-right:20px">
                    <table width="100%" border="0" cellpadding="0" cellspacing="5">
		    	<tr>
				<td id="main" class="bordered">
					<?php echo $_smarty_tpl->getSubTemplate ("loginform.tpl.html", $_smarty_tpl->cache_id, $_smarty_tpl->compile_id, null, null, array(), 0);?>

					<table width="100%" border="0" cellpadding="0" cellspacing="0">
						<tr class='page-full-content'>
							<td  id="content" class='page-content bordered' valign="top" height="1px">
								<?php if ($_smarty_tpl->tpl_vars['user_logined']->value==1){?>
								<?php echo $_smarty_tpl->getSubTemplate ("cs_list.tpl.html", $_smarty_tpl->cache_id, $_smarty_tpl->compile_id, null, null, array(), 0);?>

								<?php }?>
							</td>
						</tr>
					</table>
				</td>
			</tr>
			<tr>
                        	<td id="copyright" class="bordered">
                        	        <?php echo $_smarty_tpl->getSubTemplate ("copyright.tpl.html", $_smarty_tpl->cache_id, $_smarty_tpl->compile_id, null, null, array(), 0);?>

                        	</td>
                        </tr>
                    </table>
                </td>
            </tr>
        </table>
    </center>
</body>
<?php if ($_smarty_tpl->tpl_vars['user_logined']->value==1){?>
<script type="text/javascript">

$(document).ready(function () {
	$.getJSON("?a=gc&m=cs_list", function(data){
		if(0 == data.err)
		{
			$("#content").html(data.data);
		}
	});
	//*/
});

</script>
<?php }?>
</html>
<?php }} ?>