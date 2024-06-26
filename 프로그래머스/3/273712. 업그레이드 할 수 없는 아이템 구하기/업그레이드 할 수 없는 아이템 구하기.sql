-- 코드를 작성해주세요
SELECT II1.ITEM_ID, II1.ITEM_NAME, II1.RARITY
FROM ITEM_INFO II1
WHERE II1.ITEM_ID IN (
    SELECT II2.ITEM_ID
    FROM ITEM_INFO II2
        LEFT JOIN ITEM_TREE IT
        ON II2.ITEM_ID = IT.PARENT_ITEM_ID
    WHERE IT.ITEM_ID IS NULL
)
ORDER BY II1.ITEM_ID DESC