import prompts from 'prompts';
import { spawn, exec } from 'child_process';

const response = await prompts({
  type: 'select',
  name: 'framework',
  message: 'Select a framework',
  choices: [
    { title: 'Саня', value: 'react' },
    { title: 'Денис', value: 'vue' },
    { title: 'Vanilla', value: 'vanilla' }
  ]
});

const child = spawn('./Lab3');

child.stdout.on('data', (data) => {
  console.log(`C++ says: ${data}`)
})


// console.log(response);