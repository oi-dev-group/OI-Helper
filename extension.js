// The module 'vscode' contains the VS Code extensibility API
// Import the module and reference it with the alias vscode in your code below
const vscode = require('vscode');
const fs = require('fs');
// this method is called when your extension is activated
// your extension is activated the very first time the command is executed
/**
 * @param {vscode.ExtensionContext} context
 */
const Templates=new Array('Quick Sort With STL/STL版快速排序','Stable Sort With STL/STL版稳定排序','DSU/并查集','Floyd/佛洛依德','Interval Sum By Segment Tree/用线段树求区间和');
const TemplatesFileName=new Array('QuickSort_STL.cpp','StableSort_STL.cpp','DSU.cpp','Floyd.cpp','IntervalSum_SegmentTree.cpp');
function activate(context) {
	let disposable = vscode.commands.registerCommand('oihelper.import',function () {
		var WhichOne;
		vscode.window.showQuickPick(Templates,{
			canPickMany: false,
			ignoreFocusOut: true,
			placeHolder: "Select a Templates/选择模板"
		}).then(
			function GetTemplates(SelectTemplates){
				for(var i=0;i<Templates.length;i++){
					if(SelectTemplates==Templates[i]){
						WhichOne=i;
						break;
					}
				}
				var TemplateCode=fs.readFileSync(__dirname+'/Templates/'+TemplatesFileName[WhichOne]);
				console.log(TemplateCode.toString());
				vscode.window.activeTextEditor.edit(editBuilder => {
					const end=new vscode.Position(vscode.window.activeTextEditor.document.lineCount+1,0);
					editBuilder.replace(new vscode.Range(new vscode.Position(0, 0), end),TemplateCode.toString());
				});
			}
		)
	});

	context.subscriptions.push(disposable);
}
exports.activate = activate;

// this method is called when your extension is deactivated
function deactivate() {}

module.exports = {
	activate,
	deactivate
}
