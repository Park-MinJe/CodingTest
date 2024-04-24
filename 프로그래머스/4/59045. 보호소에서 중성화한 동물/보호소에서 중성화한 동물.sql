-- 코드를 입력하세요
SELECT AI.ANIMAL_ID, AI.ANIMAL_TYPE, AI.NAME
FROM ANIMAL_INS AI, ANIMAL_OUTS AO
WHERE AI.ANIMAL_ID=AO.ANIMAL_ID
    AND SEX_UPON_INTAKE LIKE 'Intact%'
    AND (SEX_UPON_OUTCOME LIKE 'Spayed%'
        OR SEX_UPON_OUTCOME LIKE 'Neutered%')
ORDER BY AI.ANIMAL_ID