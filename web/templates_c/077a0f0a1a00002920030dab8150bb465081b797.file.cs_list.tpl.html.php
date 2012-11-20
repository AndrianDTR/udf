<?php /* Smarty version Smarty-3.1.12, created on 2012-11-20 16:50:05
         compiled from "./templates/cs_list.tpl.html" */ ?>
<?php /*%%SmartyHeaderCode:139156528350ab989e1af179-96041800%%*/if(!defined('SMARTY_DIR')) exit('no direct access allowed');
$_valid = $_smarty_tpl->decodeProperties(array (
  'file_dependency' => 
  array (
    '077a0f0a1a00002920030dab8150bb465081b797' => 
    array (
      0 => './templates/cs_list.tpl.html',
      1 => 1350649197,
      2 => 'file',
    ),
  ),
  'nocache_hash' => '139156528350ab989e1af179-96041800',
  'function' => 
  array (
  ),
  'variables' => 
  array (
    'csList' => 0,
    'it' => 0,
  ),
  'has_nocache_code' => false,
  'version' => 'Smarty-3.1.12',
  'unifunc' => 'content_50ab989e1f3930_44954502',
),false); /*/%%SmartyHeaderCode%%*/?>
<?php if ($_valid && !is_callable('content_50ab989e1f3930_44954502')) {function content_50ab989e1f3930_44954502($_smarty_tpl) {?><table border="0" width="100%" class="championship-list tBordered" cellspacing="0" cellpadding="5px">
<tr>
	<th colspan="3"><div class="table-title"><nobr>Avaliable championships:</nobr></div></th>
</tr>

<?php  $_smarty_tpl->tpl_vars['it'] = new Smarty_Variable; $_smarty_tpl->tpl_vars['it']->_loop = false;
 $_from = $_smarty_tpl->tpl_vars['csList']->value; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array');}
foreach ($_from as $_smarty_tpl->tpl_vars['it']->key => $_smarty_tpl->tpl_vars['it']->value){
$_smarty_tpl->tpl_vars['it']->_loop = true;
?>

<tr>
	<td><div class="col-title">Date:</div><div class="col-data"><?php echo $_smarty_tpl->tpl_vars['it']->value['date'];?>
</div></td>
	<td colspan="2"><div class="col-title">Name:</div><div class="col-data"><a href="#" class="cs_teams link" id="<?php echo $_smarty_tpl->tpl_vars['it']->value['id'];?>
"><?php echo $_smarty_tpl->tpl_vars['it']->value['name'];?>
</a></div></td>
</tr>
<tr>
	<td width="1px"><div class="col-title"><nobr>Registration period:</nobr></div><div class="col-data"><nobr><?php echo $_smarty_tpl->tpl_vars['it']->value['reg_open'];?>
 - <?php echo $_smarty_tpl->tpl_vars['it']->value['reg_close'];?>
</nobr></div></td>
	<td width="1px"><div class="col-title"><nobr>Type:</nobr></div><div class="col-data"><nobr><?php echo $_smarty_tpl->tpl_vars['it']->value['type'];?>
</nobr></div></td>
	<td><div class="col-title">Categories:</div><div class="col-data"><?php echo implode(", ",$_smarty_tpl->tpl_vars['it']->value['categories_list']);?>
</div></td>
</tr>
<tr>
	<td colspan="3"><div class="col-title"><nobr>Additional info:</nobr></div><div class="col-data"><?php echo $_smarty_tpl->tpl_vars['it']->value['additional_info'];?>
</div></td>
</tr>

<tr>
	<td colspan="3"></td>
</tr>
<?php } ?>
</table>
<script type="text/javascript">

$(document).ready(function () {
	$(".cs_teams").each(function(i){
		$(this).click(function(e){
			e.preventDefault();
			id = $(this).attr('id');
			$.getJSON("?a=gc&m=cs_teams&id="+id, function(data){
				if(0 == data.err)
				{
					$("#content").html(data.data);
				}
			});
		});
	});
});

</script>
<?php }} ?>