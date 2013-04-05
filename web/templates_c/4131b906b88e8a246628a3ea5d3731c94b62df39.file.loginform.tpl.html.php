<?php /* Smarty version Smarty-3.1.12, created on 2012-11-20 16:05:45
         compiled from "./templates/loginform.tpl.html" */ ?>
<?php /*%%SmartyHeaderCode:36612503250ab8e392e5b76-93998670%%*/if(!defined('SMARTY_DIR')) exit('no direct access allowed');
$_valid = $_smarty_tpl->decodeProperties(array (
  'file_dependency' => 
  array (
    '4131b906b88e8a246628a3ea5d3731c94b62df39' => 
    array (
      0 => './templates/loginform.tpl.html',
      1 => 1350649197,
      2 => 'file',
    ),
  ),
  'nocache_hash' => '36612503250ab8e392e5b76-93998670',
  'function' => 
  array (
  ),
  'variables' => 
  array (
    'user_logined' => 0,
    'message' => 0,
  ),
  'has_nocache_code' => false,
  'version' => 'Smarty-3.1.12',
  'unifunc' => 'content_50ab8e392f7b03_19986774',
),false); /*/%%SmartyHeaderCode%%*/?>
<?php if ($_valid && !is_callable('content_50ab8e392f7b03_19986774')) {function content_50ab8e392f7b03_19986774($_smarty_tpl) {?><center>
<form name="login" action="#" method="post" id="loginform">
<table border="0" cellpadding="0" cellspacing="5px" width="500px">
	<?php if ($_smarty_tpl->tpl_vars['user_logined']->value==0){?>
	<tr>
		<td align="center" colspan="2">
			Please login
		</td>							
	</tr>
	<tr class="message">
		<td align="center" colspan="2">
			<?php echo $_smarty_tpl->tpl_vars['message']->value;?>

		</td>							
	</tr>
	<tr>
		<td align="left">
			Login
		</td>
		<td align="left">
			<input type="text" id="user" name="user" value="" />
		</td>							
	</tr>
	<tr>
		<td align="left">
			Password
		</td>
		<td align="left">
			<input type="password" id="pass" name="pass" value="" />
		</td>							
	</tr>
	<tr>
		<td align="center" colspan="2">
			<span class="button button-small" id="b-ok">Login</span>
			<input type="hidden" name="a" value="login" />
		</td>							
	</tr>
	<script type="text/javascript">
	
	$(document).ready(function () {
		$("#b-ok").click(function(e){
			e.preventDefault();
			$('#loginform').submit();
		});
	});
	
	</script>
	<?php }else{ ?>
	<tr>
		<td align="center" colspan="2">
			<input type="hidden" name="a" value="logout" />
			<span class="button button-small" id="b-ok">Logout</span>
		</td>							
	</tr>
	<script type="text/javascript">
	
	$(document).ready(function () {
		$("#b-ok").click(function(e){
			e.preventDefault();
			$('#loginform').submit();
		});
	});
	
	</script>
	<?php }?>
</table>
</form>
</center>

<?php }} ?>