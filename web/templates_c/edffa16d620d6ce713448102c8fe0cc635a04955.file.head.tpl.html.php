<?php /* Smarty version Smarty-3.1.12, created on 2012-11-20 16:05:45
         compiled from "./templates/head.tpl.html" */ ?>
<?php /*%%SmartyHeaderCode:28413783850ab8e392bba56-46676531%%*/if(!defined('SMARTY_DIR')) exit('no direct access allowed');
$_valid = $_smarty_tpl->decodeProperties(array (
  'file_dependency' => 
  array (
    'edffa16d620d6ce713448102c8fe0cc635a04955' => 
    array (
      0 => './templates/head.tpl.html',
      1 => 1350649197,
      2 => 'file',
    ),
  ),
  'nocache_hash' => '28413783850ab8e392bba56-46676531',
  'function' => 
  array (
  ),
  'variables' => 
  array (
    'PORTAL_TITLE' => 0,
    'PORTAL_DESCRIPTION' => 0,
    'PORTAL_KEYWORDS' => 0,
    'PORTAL_GENERATOR' => 0,
  ),
  'has_nocache_code' => false,
  'version' => 'Smarty-3.1.12',
  'unifunc' => 'content_50ab8e392e2b42_95080839',
),false); /*/%%SmartyHeaderCode%%*/?>
<?php if ($_valid && !is_callable('content_50ab8e392e2b42_95080839')) {function content_50ab8e392e2b42_95080839($_smarty_tpl) {?><head>
<base href="<?php echo @URL;?>
" />
<link type="text/css" rel="stylesheet" href="<?php echo @URL;?>
css/style.css"/>

<link rel="stylesheet" type="text/css" media="screen" href="<?php echo @URL;?>
css/niftycorners.css" >

<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<meta name="title" content="<?php echo $_smarty_tpl->tpl_vars['PORTAL_TITLE']->value;?>
" />
<meta name="description" content="<?php echo $_smarty_tpl->tpl_vars['PORTAL_DESCRIPTION']->value;?>
" />
<meta name="keywords" content="<?php echo $_smarty_tpl->tpl_vars['PORTAL_KEYWORDS']->value;?>
" />
<meta name="generator" content="<?php echo $_smarty_tpl->tpl_vars['PORTAL_GENERATOR']->value;?>
" />

<title><?php echo $_smarty_tpl->tpl_vars['PORTAL_TITLE']->value;?>
</title>


<script type="text/javascript" src="http://code.jquery.com/jquery.min.js">
</script>
<script type="text/javascript">
function trim(stringToTrim) {
	return stringToTrim.replace(/^\s+|\s+$/g,"");
}
</script>

</head>
<?php }} ?>