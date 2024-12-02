const header = document.querySelector("header#header")

header.style.textAlign = "center"

header.innerHTML += "<h1>Dante Alves e Silva</h1><p>Desenvolvedor Front-End | Habilidades em HTML, CSS, JavaScript</p>"

const container = document.querySelector("main#main")

//Sobre mim

aboutDiv = document.createElement("div")
aboutDiv.id = "about"

aboutDiv.innerHTML = "<h3>Sobre mim</h3><p>Sou uma pessoa muito focada, busco alcançar o sucesso na minha carreira, e me desenvolver enquanto pessoa e enquanto profissional. Eu sempre tive interesse e afinidade com tecnologia, fator que que me fez ingressar na área. Almejo aprender e aperfeiçoar meus conhecimentos acerca da programação e da Ciência da Computação como um todo.<br>Atualmente, estou no 1º Semestre da faculdade de Ciência da Computação, e buscando meu primeiro estágio como Front-End, onde espero adquirir muito conhecimento e também aprimorar minhas noções de trabalho em equipe.</p><hr>"

container.appendChild(aboutDiv)

//Formação acadêmica

academicDiv = document.createElement("div")
academicDiv.id = "academic"

academicDiv.innerHTML = "<h3>Formação Acadêmica</h3><p>Graduando em Ciência da Computação (2024 - 2028) - Unipê</p><p>Ex-Graduando em Psicologia na UFPB - (2022 - 2024)</p><hr>"

container.appendChild(academicDiv)

//Experiência

experienceDiv = document.createElement("div")
experienceDiv.id = "experience"

experienceDiv.innerHTML = "<h3>Experiência</h3><p><strong>Pesquisa sobre Desenvolvimento Moral (1 ano) -</strong> Durante a graduação de Psicologia, realizei pesquisa científica acerca do Desenvolvimento Moral na UFPB.</p><p><strong>Actuar Consultoria, Empresa Júnior de Psicologia -  (1 ano) - </strong>Trabalhei com gestão de projetos em consultoria na área de Psicologia do Trabalho, e com a administração do caixa da empresa. Tais tarefas me foram úteis para o desenvolvimento de minhas soft skills, uma vez que exigia muita comunicação assertiva, trabalho em equipe, organização e liderança.</p><hr>"


container.appendChild(experienceDiv)

//Habilidades Profissionais
skillsDiv = document.createElement("div")
skillsDiv.id = "skills"

skillsDiv.innerHTML = "<h3>Habilidades Profissionais</h3><div id=\"skills-container\"><h4>Linguagens</h4></div><h4>Habilidades Comportamentais</h4><ul><li>Proatividade</li><li>Liderança</li><li>Tomada de Decisões</li><li>Comunicação</li><li>Trabalho em Equipe</li><li>Resolução de Problemas</li><li>Organização</li><li>Resiliência</li><li>Gestão de Tempo</li></ul><h4>Idiomas</h4><ul><li>Português Nativo</li><li>Inglês Intermediário</li><li>Espanhol Básico</li></ul>"

container.appendChild(skillsDiv)

// Seleciona o contêiner onde as barras serão adicionadas
const skillsContainer = document.getElementById("skills-container");

// Array de habilidades com nome, descrição e porcentagem para cada barra
const skills = [
    { name: "HTML", description: "Estrutura de páginas web com tags e semântica.", color: "#ff5722", level: 80 },
    { name: "CSS", description: "Estilização de páginas com flexbox, grid e animações.", color: "#2196f3", level: 70 },
    { name: "JavaScript", description: "Interatividade, manipulação do DOM e lógica de programação.", color: "#ffc107", level: 50 },
    { name: "C", description: "Lógica de programação e manipulação de memória.", color: "#09ee09", level: 70 },
    { name: "PHP", description: "Armazenamento de dados e manipulação de formulários.", color: "#520dd3", level: 40 }
];

// Função para criar uma barra de habilidade
function createSkillBar(skill) {
    // Cria o contêiner principal da habilidade
    const skillDiv = document.createElement("div");
    skillDiv.classList.add("skill");

    // Cria o título da habilidade
    const skillTitle = document.createElement("p");
    skillTitle.textContent = skill.name;
    skillDiv.appendChild(skillTitle);

    // Cria o contêiner da barra de progresso
    const progressBar = document.createElement("div");
    progressBar.classList.add("progress-bar");
    skillDiv.appendChild(progressBar);

    // Cria a barra de preenchimento e define a cor e a largura inicial (0 para animação)
    const progressFill = document.createElement("div");
    progressFill.classList.add("progress-fill");
    progressFill.style.backgroundColor = skill.color;
    progressFill.style.width = "0"; // Começa com 0% para animar
    progressBar.appendChild(progressFill);

    // Cria a descrição da habilidade
    const skillDescription = document.createElement("p");
    skillDescription.textContent = skill.description;
    skillDiv.appendChild(skillDescription);

    // Adiciona o contêiner da habilidade ao contêiner principal
    skillsContainer.appendChild(skillDiv);

    // Anima a barra de progresso até o nível de habilidade especificado
    animateProgressBar(progressFill, skill.level);
}

// Função para animar a barra de progresso
function animateProgressBar(bar, targetWidth) {
    let width = 0;
    const interval = setInterval(() => {
        if (width >= targetWidth) {
            clearInterval(interval);
        } else {
            width++;
            bar.style.width = width + "%";
        }
    }, 10); // Ajuste a velocidade da animação conforme necessário
}

// Adiciona cada habilidade à página
skills.forEach(createSkillBar);


//Estilo CSS
const style = document.createElement("style");
style.textContent = `
    .skill {
        margin-bottom: 20px;
    }

    .progress-bar {
        width: 100%;
        background-color: #e0e0e0;
        border-radius: 10px;
        overflow: hidden;
        height: 20px;
        margin-top: 5px;
        margin-bottom: 5px;
    }

    .progress-fill {
        height: 100%;
        border-radius: 10px 0 0 10px;
    }
`;

// Adiciona o estilo ao documento
document.head.appendChild(style);
